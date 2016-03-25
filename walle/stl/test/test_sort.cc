#include <walle/stl/sort.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	vector<int> a;

	a.push_back(52);
	a.push_back(12);
	a.push_back(23);
	a.push_back(2);
	a.push_back(22);

	vector<int>::iterator b = a.begin();
	vector<int>::iterator e = a.end();

	insertion_sort(b,e);

	for(b = a.begin(); b != a.end(); b++) 
	{
		cout<<*b<<endl;
	}
	return 0;
}
