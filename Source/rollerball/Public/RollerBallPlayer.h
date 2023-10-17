// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "RollerBallPlayer.generated.h"

//Forward Declarations
//class UCameraComponent;
//class USpringArmComponent;

UCLASS()
class ROLLERBALL_API ARollerBallPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARollerBallPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForce = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpImpulse = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxJumpCont = 1;
	

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
