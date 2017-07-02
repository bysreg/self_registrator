#pragma once

#include "object.hpp"

#include <unordered_map>
#include <string>

class ObjectFactory
{
public:

	using ObjectFactoryFunctionType = Object*(*)();
	using FactoryMapType = std::unordered_map<std::string, ObjectFactoryFunctionType>;

	FactoryMapType factory_map;

	Object* Create(const std::string& type)
	{
		if (factory_map.find(type) == factory_map.end())
		{
			return new Object;
		}

		return factory_map[type]();
	}

	void Register(const std::string& type, ObjectFactoryFunctionType factory_function)
	{
		factory_map[type] = factory_function;
	}

	static ObjectFactory& Instance()
	{
		static ObjectFactory self;
		return self;
	}
};

class ObjectFactoryRegistrator
{
public:
	ObjectFactoryRegistrator(const std::string& type, ObjectFactory::ObjectFactoryFunctionType factory_function)
	{
		printf("register is called\n");

		ObjectFactory::Instance().Register(type, factory_function);
	}
};

#define CREATE_FUNCTION_NAME(ObjectType, ObjectString) Create ## _ ## ObjectType ## _ ## ObjectString

#define REGISTER(ObjectType, ObjectString)\
	static Object* CREATE_FUNCTION_NAME(ObjectType, ObjectString)()\
	{\
		/*the parameter of this function has to match Object's constructor parameter*/ \
		return new ObjectType;\
	}\
	static ObjectFactoryRegistrator registrator(# ObjectString, &CREATE_FUNCTION_NAME(ObjectType, ObjectString));\

