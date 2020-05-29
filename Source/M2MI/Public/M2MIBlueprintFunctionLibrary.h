// crssnky

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "M2MI_MaterialType.h"
#include "M2MIBlueprintFunctionLibrary.generated.h"

class UMaterialInterface;
class UMaterialExpression;
class UTexture2D;

/**
 *
 */
UCLASS()
class M2MI_API UM2MIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "Material|M2MI")
		static EMaterialType_M2MI GetMaterialType(const UMaterialInterface* material);
	UFUNCTION(BlueprintPure, Category = "Material|M2MI")
		static FLinearColor GetMaterialColorInOneColorMaterial(const UMaterialInterface* material);
	UFUNCTION(BlueprintPure, Category = "Material|M2MI")
		static UTexture2D* GetMaterialColorInOneTextureMaterial(const UMaterialInterface* material);
	UFUNCTION(BlueprintPure, Category = "Material|M2MI")
		static TArray<UTexture2D*> GetMaterialColorInOneTextureAndNormal(const UMaterialInterface* material);

private:
	static EMaterialType_M2MI GetMaterialType_2Expressions(const TArray<UMaterialExpression*>& expressions);
	static EMaterialType_M2MI GetMaterialType_1Expression(const TArray<UMaterialExpression*>& expressions);
};
