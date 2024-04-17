#include <iostream>
#include "List.h"
#include <list>
using namespace std;

int main()
{
    List<int> l;
	try
	{
		cout << l[0];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
    1
   




    
    return 0;
}
