// Fill out your copyright notice in the Description page of Project Settings.


#include "SItemChest.h"



// Sets default values
ASItemChest::ASItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(Mesh);
	TargetPitch = 110.0f; // Set the target pitch for the lid rotation

}
void ASItemChest::Interact_Implementation(AActor* InstigatorActor)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}
// Called when the game starts or when spawned
void ASItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

