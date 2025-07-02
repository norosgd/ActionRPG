// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetSimulatePhysics(true);
	
	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	RadialForceComp->SetupAttachment(RootComponent); // Attach the radial force component to the root component
	RadialForceComp->Radius = 1000.0f; // Set the radius for the radial force
	RadialForceComp->ImpulseStrength = 2000.0f; // Set the impulse strength for the radial force'
	RadialForceComp->ForceStrength = 10.0f; // Set the force strength for the radial force
	RadialForceComp->bImpulseVelChange = true; // Enable impulse velocity change
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	MeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnHit); // Bind the OnHit function to the OnComponentHit event
}

void ASExplosiveBarrel::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComp->FireImpulse(); // Trigger the radial force impulse
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnHit"));
}


