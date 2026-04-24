#include "NewActor.h"

ANewActor::ANewActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANewActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	// 시작부터 반대 방향 이동
	MoveSpeed = -FMath::Abs(MoveSpeed);
}

void ANewActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 🔁 반대 방향 회전
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

	// ↔ 왕복 이동
	FVector CurrentLocation = GetActorLocation();
	float Distance = FVector::Dist(StartLocation, CurrentLocation);

	if (Distance >= MaxRange)
	{
		MoveSpeed *= -1.0f; // 방향 반전
	}

	FVector NewLocation = CurrentLocation;
	NewLocation.X += MoveSpeed * DeltaTime;

	SetActorLocation(NewLocation);
}
