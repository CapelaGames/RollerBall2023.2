// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/RollerBallModeBase.h"

#include "Game/RollerBallWidget.h"
#include "items/RollerBallItemBase.h"
#include "Kismet/GameplayStatics.h"

void ARollerBallModeBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARollerBallItemBase::StaticClass(), Items);
	ItemsInLevel = Items.Num();

	if(GameWidgetClass)
	{
		GameWidget = Cast<URollerBallWidget>(CreateWidget(GetWorld(), GameWidgetClass));

		if(GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateItemText();
		}
	}
}

void ARollerBallModeBase::UpdateItemText()
{
	GameWidget->SetItemText(ItemsCollected, ItemsInLevel);
}

void ARollerBallModeBase::ItemCollected()
{
	ItemsCollected++;
	UpdateItemText();
}
