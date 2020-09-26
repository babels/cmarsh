#include <stdio.h>

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)



EXTERN_DLL_EXPORT
int
bar() {
  return 42;
}

//EXTERN_DLL_EXPORT
extern int(*(CsharpFunction))(int a, float b);


	// C++ function that C# calls
	// Takes the function pointer for the C# function that C++ can call
EXTERN_DLL_EXPORT
void Init(int(*csharpFunctionPtr)(int, float))
	{
		CsharpFunction = csharpFunctionPtr;
	}

	// Example function that calls into C#
EXTERN_DLL_EXPORT
int Foo()
	{
		// It's just a function call like normal!
		int retVal = CsharpFunction(2, 3.14f);
                return retVal;
	}
