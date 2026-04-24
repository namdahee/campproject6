#include "Item.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

DEFINE_LOG_CATEGORY(LogSparta);

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("'/Game/StarterContent/Materials/M_Metal_Brushed_Nickel.M_Metal_Brushed_Nickel'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void AItem::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	OnItemPickedUp();

	// 초기 위치 세팅
	SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
	SetActorScale3D(FVector(2.0f));

	// ? 반드시 위치 세팅 후 저장
	StartLocation = GetActorLocation();
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 회전
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

	// 이동 (왕복)
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

void AItem::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AItem::OnItemPickedUp()
{
	UE_LOG(LogSparta, Warning, TEXT("Item Picked Up!"));
}

void AItem::ResetActorPosition()
{
	SetActorLocation(StartLocation);
}

float AItem::GetRotationSpeed() const
{
	return RotationSpeed;
}
