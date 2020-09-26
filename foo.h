#ifndef pivk_h__
#define pivk_h__

//#ifdef LIBRARY_EXPORTS
//#define LIBRARY_API __declspec(dllexport);
//#else
#define LIBRARY_API __declspec(dllimport);
//#endif

#define KSZ 12
int bar();

int (*CsharpFunction)(int a, float b);

void Init(int(*csharpFunctionPtr)(int, float));

int Foo();


#endif  // pivk_h__
