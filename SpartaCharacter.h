#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TEST5_API ASpartaCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ASpartaCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComp;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION()
    void Move(const FInputActionValue& Value);

    UFUNCTION()
    void StartJump(const FInputActionValue& Value);

    UFUNCTION()
    void StopJump(const FInputActionValue& Value);

    UFUNCTION()
    void Look(const FInputActionValue& Value);

    UFUNCTION()
    void StartSprint(const FInputActionValue& Value);

    UFUNCTION()
    void StopSprint(const FInputActionValue& Value);

private:
    float NormalSpeed;
    float SprintSpeedMultiplier;   // ← 수정
    float SprintSpeed;
};
