#pragma once

#include "string.h"
#include "TestDll.h"


//Exported method that invertes a given boolean.
bool DLL_EXPORT getInvertedBool(bool boolState)
{
	return bool(!boolState);
}

//Exported method that iterates a given int value.
int DLL_EXPORT getIntPlusPlus(int lastInt)
{
	return int(++lastInt);
}

//Exported method that calculates the are of a circle by a given radius.
float DLL_EXPORT getCircleArea(float radius)
{
	return float(3.1416f * (radius * radius));
}

//Exported method that adds a parameter text to an additional text and returns them combined.
char DLL_EXPORT *getCharArray(char* parameterText)
{
	char* additionalText = " world!";

	if (strlen(parameterText) + strlen(additionalText) + 1 > 256)
	{
		return "Error: Maximum size of the char array is 256 chars.";
	}

	char combinedText[256] = "";

	strcpy_s(combinedText, 256, parameterText);
	strcat_s(combinedText, 256, additionalText);

	return (char*)combinedText;
}

//Exported method that adds a vector4 to a given vector4 and returns the sum.
float DLL_EXPORT *getVector4(float x, float y, float z, float w)
{
	float* modifiedVector4 = new float[4];

	modifiedVector4[0] = x + 1.0F;
	modifiedVector4[1] = y + 2.0F;
	modifiedVector4[2] = z + 3.0F;
	modifiedVector4[3] = w + 4.0F;

	return (float*)modifiedVector4;
}