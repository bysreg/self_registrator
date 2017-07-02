#include "define.hpp"
#include "derived_object.hpp"

DerivedObject::DerivedObject()
{
	printf("ctor derived object is called\n");
}

REGISTER(DerivedObject, DerivedType)

//// expanded version of the macro
//static Object* ObjectType_ObjectString()
//{
//	return new DerivedObject;
//}
//
//static ObjectFactoryRegistrator registrator("DerivedType", &ObjectType_ObjectString);
