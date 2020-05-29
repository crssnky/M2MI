// crssnky


#include "M2MIBlueprintFunctionLibrary.h"
#include "Materials/Material.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Engine/Texture2D.h"
#include "UObject/UObjectBaseUtility.h"

EMaterialType_M2MI UM2MIBlueprintFunctionLibrary::GetMaterialType(const UMaterialInterface* material) {
	EMaterialType_M2MI ret = EMaterialType_M2MI::Other;
	const auto& expressions = material->GetMaterial()->Expressions;

	if (expressions.Num() == 2) {
		ret = GetMaterialType_2Expressions(expressions);
	}
	else if (expressions.Num() == 1) {
		ret = GetMaterialType_1Expression(expressions);
	}

	return ret;
}

FLinearColor UM2MIBlueprintFunctionLibrary::GetMaterialColorInOneColorMaterial(const UMaterialInterface* material)
{
	FLinearColor ret(1.f, 1.f, 1.f, 1.f);

	const auto& expressions = material->GetMaterial()->Expressions;
	if (expressions.Num() == 1) {
		const auto* const vecParam = Cast<UMaterialExpressionVectorParameter>(expressions[0]);
		if (vecParam) {
			ret = vecParam->DefaultValue;
		}
	}

	return ret;
}

UTexture2D* UM2MIBlueprintFunctionLibrary::GetMaterialColorInOneTextureMaterial(const UMaterialInterface* material)
{
	UTexture2D* ret = nullptr;

	const auto& expressions = material->GetMaterial()->Expressions;
	if (expressions.Num() == 1) {
		const auto* const texParam = Cast<UMaterialExpressionTextureSample>(expressions[0]);
		if (texParam) {
			ret = Cast<UTexture2D>(texParam->Texture);
		}
	}

	return ret;
}

TArray<UTexture2D*> UM2MIBlueprintFunctionLibrary::GetMaterialColorInOneTextureAndNormal(const UMaterialInterface* material)
{
	TArray<UTexture2D*> ret = { nullptr,nullptr };

	const auto& expressions = material->GetMaterial()->Expressions;
	if (expressions.Num() == 2) {
		for (const auto& expression : expressions) {
			const auto* const texParam = Cast<UMaterialExpressionTextureSample>(expression);
			switch (texParam->SamplerType)
			{
			case EMaterialSamplerType::SAMPLERTYPE_Color:
				ret[0] = Cast<UTexture2D>(texParam->Texture);
				break;
			case EMaterialSamplerType::SAMPLERTYPE_Normal:
				ret[1] = Cast<UTexture2D>(texParam->Texture);
				break;
			default:
				break;
			}
		}
	}

	return ret;
}

EMaterialType_M2MI UM2MIBlueprintFunctionLibrary::GetMaterialType_2Expressions(const TArray<UMaterialExpression*>& expressions)
{
	EMaterialType_M2MI ret = EMaterialType_M2MI::Other;

	if (expressions[0]->GetClass() == UMaterialExpressionTextureSample::StaticClass()
		&& expressions[1]->GetClass() == UMaterialExpressionTextureSample::StaticClass()) {
		ret = EMaterialType_M2MI::OneTextureAndNormal;
	}

	return ret;
}

EMaterialType_M2MI UM2MIBlueprintFunctionLibrary::GetMaterialType_1Expression(const TArray<UMaterialExpression*>& expressions)
{
	EMaterialType_M2MI ret = EMaterialType_M2MI::Other;

	const auto* const expression = expressions[0]->GetClass();

	if (expression == UMaterialExpressionTextureSample::StaticClass()) {
		ret = EMaterialType_M2MI::OneTexture;
	}
	else if (expression == UMaterialExpressionVectorParameter::StaticClass()) {
		ret = EMaterialType_M2MI::OneColor;
	}

	return ret;
}
