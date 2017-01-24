# Unreal Engine DLL import example
**Example Unreal Engine project for importing external dll and using its functionality in blueprints.**

Based on https://wiki.unrealengine.com/Linking_Dlls but optimized to be easier to use and requires less boilerplate code.

## Tips
- The DLL code is in "TestDll" folder, open it with VS Community 2015.
- The library import code is in Source/DllTestProject/DllTestProject.h/.cpp files
- The test blueprint is in Content/Blueprints/BP_TestDllLibrary