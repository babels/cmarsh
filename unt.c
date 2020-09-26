#include <stdio.h>

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)



EXTERN_DLL_EXPORT
int
bar() {
  return 42;
}

struct
Vector3
{
   float x;
   float y;
   float z;
};


////////////////////////////////////////////////////////////////
// C# functions for C++ to call
////////////////////////////////////////////////////////////////

int (*GameObjectNew)();

int (*GameObjectGetTransform)(int thisHandle);

void (*TransformSetPosition)(int thisHandle, Vector3 position);

////////////////////////////////////////////////////////////////
// C++ functions for C# to call
////////////////////////////////////////////////////////////////

int numCreated;

EXTERN_DLL_EXPORT
void
Init
   (   int  (*gameObjectNew)(),
       int  (*gameObjectGetTransform)(int),
      void  (*transformSetPosition)(int, Vector3) )
{
  GameObjectNew           =  gameObjectNew;
  GameObjectGetTransform  =  gameObjectGetTransform;
  TransformSetPosition    =  transformSetPosition;

  numCreated = 0;
}

EXTERN_DLL_EXPORT
void
MonoBehaviourUpdate
   (int thisHandle)
{
  if (numCreated < 10) {
     int goHandle = GameObjectNew();
     int transformHandle = GameObjectGetTransform(goHandle);
     float comp = (float)numCreated;
     Vector3 position = { comp, comp, comp };
     TransformSetPosition(transformHandle, position);
     numCreated++;
  }
}
