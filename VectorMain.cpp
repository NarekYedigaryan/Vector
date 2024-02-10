
#include <iostream>
#include "Vector.h"
#include <string>

int main()
{
    Vector<std::string> v;
    v.push_back("jndwnd");
    v.push_back("jwndjwn");
    v.push_back("jwndwn");
    v.push_back("jndjwnd");
   std::cout << v.getM_capacity();
   
}
