#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestDllLibrary.generated.h"

// based on https://wiki.unrealengine.com/Linking_Dlls but with much less boilerplate code

UCLASS()
class DLLTESTPROJECT_API UTestDllLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	// loads dll
	UFUNCTION(BlueprintCallable, Category = "Test library")
		static bool loadTestDll(FString folder = "TestDll", FString name = "TestDll.dll");

	// unloads dll
	UFUNCTION(BlueprintCallable, Category = "Test library")
		static void unloadTestDll();

	// imported methods
	UFUNCTION(BlueprintCallable, Category = "Test library")
		static bool getInvertedBool(bool boolState);

	UFUNCTION(BlueprintCallable, Category = "Test library")
		static int getIntPlusPlus(int lastInt);

	UFUNCTION(BlueprintCallable, Category = "Test library")
		static float getCircleArea(float radius);

	UFUNCTION(BlueprintCallable, Category = "Test library")
		static FString getCharArray(FString parameterText);

	UFUNCTION(BlueprintCallable, Category = "Test library")
		static FVector4 getVector4(FVector4 vector4);


	
};