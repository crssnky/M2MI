// crssnky

#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "MeshSelectWidget.generated.h"

/**
 *
 */
UCLASS()
class M2MI_API UMeshSelectWidget : public UNativeWidgetHost
{
	GENERATED_BODY()
public:
	UMeshSelectWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SelectedItemPath;

};
