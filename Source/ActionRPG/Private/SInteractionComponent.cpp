// Fill out your copyright notice in the Description page of Project Settings.


#include "SInteractionComponent.h"
#include "SGameplayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
USInteractionComponent::USInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	InteractionDistance = 1000.0f; // Default interaction distance

	// ...
}


// Called when the game starts
void USInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USInteractionComponent::PrimaryInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HitResult1"));
	FHitResult HitResult;
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_PhysicsBody);
	AActor* Owner = GetOwner();
	FVector EndLocation;

	FVector EyeLocation;
	FRotator EyeRotation;
	Owner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	EndLocation = EyeLocation + (EyeRotation.Vector() * 1000.0f);
	bool bDidHit = GetWorld()->LineTraceSingleByObjectType(HitResult, EyeLocation, EndLocation, ObjectQueryParams);
	AActor* HitActor = HitResult.GetActor();

	//TArray<FHitResult> HitResults;
	//FCollisionShape Shape;
	//Shape.SetSphere(30.0f);
	

	//GetWorld()->SweepMultiByObjectType(HitResults, EyeLocation, EndLocation, FQuat::Identity, ObjectQueryParams, Shape);
	FColor LineColor = FColor::Green;

	//for (FHitResult Hit : HitResults)
	//
		if (HitActor)
		{
			if (HitActor->Implements<USGameplayInterface>())
			{
				ISGameplayInterface::Execute_Interact(HitActor, Owner);
				
			}
		}
		//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, InteractionDistance, 12, LineColor, false, 2.0f);
		DrawDebugLine(GetWorld(), EyeLocation, EndLocation, LineColor, false, 2.0f, 0, 5.0f);
	//}
}

