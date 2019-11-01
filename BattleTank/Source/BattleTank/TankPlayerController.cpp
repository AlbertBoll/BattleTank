// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
//#include "BattleTank.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{

	}
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
}

// Get World location of line trace through crosshair, true if it hits the landscape 
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)const
{
	//find cross-hair position.
	//de-project to the screen position of the cursor to the world direction. 
	//line trace to the hit direction to see what we hit. 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//FVector CameraWorldLocation;
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	//HitLocation = FVector(1.f);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, 
										  ScreenLocation.Y, 
		                                  CameraWorldLocation, 
		                                  LookDirection);


}


