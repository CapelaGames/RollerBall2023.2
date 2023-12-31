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
	Mesh->OnComponentHit.AddDynamic(this, &ARollerBallPlayer::OnHit);
	
	Super::BeginPlay();

	//Account for mass in moveforce
	MoveForce *= Mesh->GetMass();
	JumpImpulse *= Mesh->GetMass();
	
}




// Called to bind functionality to input
void ARollerBallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ARollerBallPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARollerBallPlayer::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this , &ARollerBallPlayer::Jump);
	//InputComponent->BindAction("Jump", IE_Released, this , &ARollerBallPlayer::Jump);
}

void ARollerBallPlayer::MoveRight(float Value)
{
	const FVector Right = Camera->GetRightVector() * MoveForce * Value;
	Mesh->AddForce(Right);
}

void ARollerBallPlayer::MoveForward(float Value)
{
	const FVector Forward = Camera->GetForwardVector() * MoveForce * Value;
	Mesh->AddForce(Forward);

	//GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange,
	//	FString::Printf(TEXT("forward pressed")));

	//UE_LOG(LogTemp, Warning, TEXT("Hello"))
	
}

void ARollerBallPlayer::Jump()
{
	if(JumpCount >= MaxJumpCont){return;}
	Mesh->AddForce(FVector(0,0,JumpImpulse));
	JumpCount++;
}

void ARollerBallPlayer::OnHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit )
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange,
		TEXT("On Hit"));
	
	float HitDirection = Hit.Normal.Z;

	if(HitDirection > 0)
	{
		JumpCount = 0;
	}
}
