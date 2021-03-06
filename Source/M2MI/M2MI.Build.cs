// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
using System.IO;
using System;
using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class M2MI : ModuleRules
	{
		public M2MI(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"UnrealEd",
					"Slate",
					"SlateCore",
					// ... add other public dependencies that you statically link with here ...
					"UMG",
					"PropertyEditor",
					"Engine",
					"AssetRegistry",
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}

		private string ModulePath {
			get { return ModuleDirectory; }
		}
	}
}
