#include <iostream>
#include <llist.h>

using namespace std;

int main()
{
	LList<int> a;
       // LList<int> c;
        //for(int i = 0;i < 10000;i++)
		//c.push_back(i);
        LList<int> b(move(a));
	for(int i = 0;i < 10000;i++)
		b.push_back(i);
        //LList d(c);

}
