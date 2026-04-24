#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Item.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSparta, Warning, All);

class UStaticMeshComponent;

UCLASS()
class TEST5_API AItem : public AActor
{
	GENERATED_BODY()

public:
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	// 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeed = 90.0f;

	// 이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed = 100.0f;

	// 이동 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxRange = 300.0f;

	// 시작 위치
	FVector StartLocation;

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UFUNCTION(BlueprintCallable)
	void OnItemPickedUp();

	UFUNCTION(BlueprintCallable)
	void ResetActorPosition();

	UFUNCTION(BlueprintCallable)
	float GetRotationSpeed() const;
};
// 생성자 - 메모리에 생김, 딱 한 번 호출.
// PostInitializeComponents() - 컴포넌트가 완성된 직후 호출, 컴포넌트끼리 데이터 주고받기, 상호작용
// BeginPlay() - 배치 (Spawn) 직후
// Tick(FLoat DeltaTime) - 매 프레임마다 호출됨.
// Destoyed() - 삭제 되기 직전에 호출된다.
// EndPlay() - 게임 종료, 파괴 (Destroyed()), 레벨 전환
