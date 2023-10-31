// Fill out your copyright notice in the Description page of Project Settings.


#include "items/RollerBallItemBase.h"



// Sets default values
ARollerBallItemBase::ARollerBallItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ARollerBallItemBase::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollerBallItemBase::OverlapBegin);
}

void ARollerBallItemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ARollerBallPlayer>(OtherActor) != nullptr)
	{
		Collected();
	}
}

void ARollerBallItemBase::Collected_Implementation()
{
	//TODO - do stuff
}

