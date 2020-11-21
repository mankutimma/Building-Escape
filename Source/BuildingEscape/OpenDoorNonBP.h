// Copyright 2020 Ashish Jagadish, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoorNonBP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoorNonBP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorNonBP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(const float& RefDeltaTime);
	void CloseDoor(const float& RefDeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
	void FindPressurePlate();

private:
	float InitialYaw;
	float CurrentYaw;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 40.f;

	float TargetYaw = 90.f;

	float DoorLastOpened = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 0.8f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 5.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	// use if only Player can open door by stepping on pressure plate
	//UPROPERTY(EditAnywhere)
	//AActor* ActorThatOpensDoor = nullptr;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;

	// Tracks whether sound has been played. Has been played measn true
	bool OpenDoorSound = false;
	bool CloseDoorSound = true;

		
};
