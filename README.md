# Self Registrator Link Optimization Problem
This project shows problem with using service locator / registry pattern 

# How to Build 
```
mkdir build
cmake ..
```

# How to Repro the Problem (*)
1 Compile
2 Notice there's no output
3 Now uncomment line 2 (the derived_object.hpp include) and line 8 (DerivedObject's instantiation)
4 Compile
5 There's output now  : 
```
register is called
ctor derived object is called
ctor derived object is called
```
6 The above output shows the problem with using the pattern in c++ if the registered object type is never referenced directly
from the executable that lives in a different static library
7 Now comment back line 2 and 8
8 Weirdly, you'll have the same output "register is called"
9 Clean the solution and compile
10 Now you don't see any output
11 This might have something to do with "Enable Incremental Linking' is set to yes. 
If that option is disabled, you won't see the "register is called" output from doing step 1-7

*) Tested in MSVC VS 2017

# Explanation
https://stackoverflow.com/questions/6372032/dynamic-initialization-phase-of-static-variables
http://en.cppreference.com/w/cpp/language/initialization#Deferred_dynamic_initialization
