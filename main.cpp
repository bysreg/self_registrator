#include "define.hpp"
//#include "derived_object.hpp"

#include <cstdio>

int main()
{
	//DerivedObject a;

	Object* test = ObjectFactory::Instance().Create("DerivedType");

	return 0;
}