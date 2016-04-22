///
///@date   2016-04-22 21:25:52
///
 
 
 
#include <iostream>
#include <stdlib.h>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class que
{
	public:
		void push(int x)
		{
			if(qu.size()==10) exit(-1);
			else 
				qu.insert(qu.begin(),x);
		}
		void pop()
		{
			qu.erase(qu.end()-1);
		}
		int front()
		{
			return qu[qu.size()-1];
		}
		int back()
		{
			return qu[0];
		}
		bool empty()
		{
			if(qu.size()==0) return true;
			else
				return false;
		}
		bool full()
		{
			if(qu.size()==10) return true;
			else
				return false;
		}
	private:
		vector<int> qu;
};

int main()
{
	que q;
	q.push(10);
	q.push(12);
	q.push(14);
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.pop();
	cout<<q.front()<<endl;  //  出队之后，队首元素改变

	return 0;
}
