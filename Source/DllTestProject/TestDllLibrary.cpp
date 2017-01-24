#include "DllTestProject.h"
#include "TestDllLibrary.h"

// generates typedef and local reference
#define DEFINE_DLL_METHOD(name, returnType, ...) typedef returnType (*_##name##)(__VA_ARGS__);\
_##name name##_ = NULL;

// defines import to local reference
#define IMPORT_DLL_METHOD(name) name##_ = (_##name##)FPlatformProcess::GetDllExport(v_dllHandle, L#name)

// imported dll handle
void *v_dllHandle;

// define imported function signatures and local references
DEFINE_DLL_METHOD(getInvertedBool, bool, bool boolState);
DEFINE_DLL_METHOD(getIntPlusPlus, int, int lastInt);
DEFINE_DLL_METHOD(getCircleArea, float, float radius);
DEFINE_DLL_METHOD(getCharArray, char*, char* parameterText);
DEFINE_DLL_METHOD(getVector4, float*, float x, float y, float z, float w);

/*
typedef bool (*_getInvertedBool)(bool boolState);
_getInvertedBool getInvertedBool_ = NULL;
*/

#define IMPORT_DLL_METHOD(name) name##_ = (_##name##)FPlatformProcess::GetDllExport(v_dllHandle, L#name)


// imports given dll and all methods from dll in project/Plugins/folder/name
bool UTestDllLibrary::loadTestDll(FString folder, FString name)
{
	FString filePath = *FPaths::GamePluginsDir() + folder + "/" + name;

	if (!FPaths::FileExists(filePath))
	{
		return false;
	}

	v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);

	if (v_dllHandle == NULL)
	{
		return false;
	}

	// import all methods
	IMPORT_DLL_METHOD(getInvertedBool);
	IMPORT_DLL_METHOD(getIntPlusPlus);
	IMPORT_DLL_METHOD(getCircleArea);
	IMPORT_DLL_METHOD(getCharArray);
	IMPORT_DLL_METHOD(getVector4);

	// getInvertedBool_ = (_getInvertedBool)FPlatformProcess::GetDllExport(v_dllHandle, L"getInvertedBool");

	return true;
}

// releases imported dll
void UTestDllLibrary::unloadTestDll()
{
	if (v_dllHandle == NULL)
	{
		return;
	}

	// release dll handle
	FPlatformProcess::FreeDllHandle(v_dllHandle);
	v_dllHandle = NULL;
}

// method conversions
bool UTestDllLibrary::getInvertedBool(bool boolState)
{
	return getInvertedBool_(boolState);
}

int UTestDllLibrary::getIntPlusPlus(int lastInt)
{
	return getIntPlusPlus_(lastInt);
}

float UTestDllLibrary::getCircleArea(float radius)
{
	return getCircleArea_(radius);
}

FString UTestDllLibrary::getCharArray(FString parameterText)
{
	return ANSI_TO_TCHAR(getCharArray_(TCHAR_TO_ANSI(*parameterText)));
}

FVector4 UTestDllLibrary::getVector4(FVector4 vector4)
{
	float* vector4Array = getVector4_(vector4.X, vector4.Y, vector4.Z, vector4.W);

	return FVector4(vector4Array[0], vector4Array[1], vector4Array[2], vector4Array[3]);
}
