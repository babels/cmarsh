#ifndef unt_h__
#define unt_h__

//#ifdef LIBRARY_EXPORTS
//#define LIBRARY_API __declspec(dllexport);
//#else
#define LIBRARY_API __declspec(dllimport);
//#endif

#define KSZ 12
int bar();

struct Vector3 {float x; float y; float z;};
extern    int  (*GameObjectNew)();
extern    int  (*GameObjectGetTransform)(int thisHandle);
extern   void  (*TransformSetPosition)(int thisHandle, Vector3 position);

         void  Init(int (*gameObjectNew)(), int (*gameObjectGetTransform)(int), void (*transformSetPosition)(int, Vector3));
         void  MonoBehaviourUpdate(int thisHandle);

#endif  // unt_h__
