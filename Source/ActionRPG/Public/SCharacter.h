// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USInteractionComponent;


UCLASS()
class ACTIONRPG_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	
	//Enhanced input variables set in blueprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* PlayerInputMappingContext; // Input mapping context for player controls

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction; // Input action for movement

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction; // Input action for looking around

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction; // Input action for jumping

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* PrimaryAttackAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* InteractAction; // Input action for interacting with objects

	// Gets the values from the InputAction struct and passes them to the movement functions
	void Move(const FInputActionValue& Value); 

	void Look(const FInputActionValue& Value); 

	// Actions
	void PrimaryAttack(); // Executes the primary attack action

	void PrimaryInteract();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass; // Class of the primary attack actor

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom; // Camera boom positioning the camera behind the character

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FollowCamera; // Follow camera

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USInteractionComponent* InteractionComponent; // Interaction component for interacting with objects in the world
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")	
	virtual void DoMove(float Right, float Forward); // Moves the character based on input values

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void DoLook(float Yaw, float Pitch); // Rotates the camera based on input values

};
