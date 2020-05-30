#include <iostream>
#include <llist.h>

using namespace std;

int main()
{       
	LList a;	
       // LList c;	
        //for(int i = 0;i < 10000;i++)	
		//c.push_back(i);	
       	for(int i = 0;i < 10000;i++)	
		a.push_back(i);	

        LList b(move(a));	
        //LList d(c);

}
