// crssnky


#include "MeshSelectWidget.h"
#include "PropertyCustomizationHelpers.h"
#include "Engine/StaticMesh.h"

UMeshSelectWidget::UMeshSelectWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer) {
	TSharedRef<SObjectPropertyEntryBox> selector = SNew(SObjectPropertyEntryBox)
		.AllowedClass(UStaticMesh::StaticClass())
		.AllowClear(false)
		.OnShouldFilterAsset_Lambda([](const FAssetData&)
			{
				return false;
			})
		.ObjectPath_Lambda([&]()
			{
				return SelectedItemPath;
			})
				.OnObjectChanged_Lambda([&](const FAssetData& AssetData)
					{
						SelectedItemPath = AssetData.ObjectPath.ToString();
					});

			SetContent(selector);
}

