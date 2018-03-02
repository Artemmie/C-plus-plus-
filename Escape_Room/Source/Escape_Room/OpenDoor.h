 // Copyright Artem Gerasimov 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "Gameframework/Actor.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_ROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void openDoor();
	void closeDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
	float openAngle = 150.0f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;
	
	UPROPERTY(EditAnywhere)
	float doorCloseDelay = 0.5f;

	float lastDoorOpenTime;
	AActor* actorOpens;
	AActor* owner = GetOwner();
};