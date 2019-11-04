// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Starting the tank move barrel 
	void AimTowardsCrosshair();
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 1.f/3;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetSightRayHitLocation(FVector& HitLocation)const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const;
	//bool GetLineTrace()
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)const;
	
	
};
