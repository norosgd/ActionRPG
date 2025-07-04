// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SItemChest.generated.h"


class UStaticMeshComponent;

UCLASS()
class ACTIONRPG_API ASItemChest : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
	void Interact_Implementation(AActor* InstigatorActor);

public:	
	// Sets default values for this actor's properties
	ASItemChest();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* LidMesh;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
	float TargetPitch;

};
