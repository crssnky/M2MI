// crssnky

#pragma once

#include "CoreMinimal.h"
#include "M2MI_MaterialType.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum class EMaterialType_M2MI : uint8
{
	OneColor = 0,
	OneTexture,
	OneTextureAndNormal,

	Other UMETA(DisplayName = "NoSupport"),

	Num UMETA(Hidden)
};
