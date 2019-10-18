// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	//Mass of the car in kg
	UPROPERTY(EditAnywhere)
	float Mass = 1000;

	//The throttle applied to the car when the throttle is fully down in newtons
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	//The number of degrees rotated per second at full control throw (degrees/s)
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 90;

	//Higher means more drag
	UPROPERTY()
	float DragCoefficient = 16;

	//Higher means more drag
	UPROPERTY()
	float RollingResistanceCoefficient = 0.1;

	FVector Velocity;

	float Throttle;

	float SteeringThrow;

	void MoveForward(float Value);

	void MoveRight(float Value);

	FVector GetAirResistance();
	FVector GetRollingResistance();

	void ApplyRotation(float DeltaTime);

	void UpdateLocationFromVelocity(float DeltaTime);

};
