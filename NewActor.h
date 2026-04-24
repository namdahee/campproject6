#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewActor.generated.h"

UCLASS()
class TEST5_API ANewActor : public AActor
{
	GENERATED_BODY()

public:
	ANewActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere)
	float RotationSpeed = -180.0f;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 300.0f;

	UPROPERTY(EditAnywhere)
	float MaxRange = 300.0f;

	FVector StartLocation;
};
