// Fill out your copyright notice in the Description page of Project Settings.


#include "RollerBallPlayer.h"

//put this in header file
//#include "Camera/CameraComponent.h"
//#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARollerBallPlayer::ARollerBallPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	Mesh->SetSimulatePhysics(true);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
}

// Called when the game starts or when spawned
void ARollerBallPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ARollerBallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

