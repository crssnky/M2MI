// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "M2MI.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "crssnkyPlugin"

class FM2MI: public IM2MI{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FM2MI, M2MI)

void FM2MI::StartupModule(){
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	UE_LOG(LogTemp, Display, TEXT("Loaded M2MI"));
	if(IsRunningCommandlet()){ return; }
}

void FM2MI::ShutdownModule(){
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogTemp, Display, TEXT("Unloaded M2MI"));
}
