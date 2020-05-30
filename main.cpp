#include <iostream>
#include <llist.h>

using namespace std;

int main()
{
	LList<int> a;
       // LList<int> c;
        //for(int i = 0;i < 10000;i++)
		//c.push_back(i);
       	for(int i = 0;i < 10000;i++)
		a.push_back(i);
        LList<int> b(move(a));
        //LList d(c);

}
