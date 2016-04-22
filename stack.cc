///
///@date   2016-04-22 21:07:40
///
 
 
 
#include <iostream>
#include <stdlib.h>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class stack
{
public:
	void push(int);
	void pop();
	int top();
	bool empty();
	bool full();
private:
	vector<int> st;          
};

void stack::push(int x)
{
	if(st.size()==10) exit(-1);            //栈满 结束进程
	else
		st.push_back(x);
}

void stack::pop()
{
	st.erase(st.end()-1);
}

int stack::top()
{
	return st[st.size()-1];
}

bool stack::empty()
{
	if(st.size()) return false;
	else
		return true;
}

bool stack::full()
{
	if(st.size()==10) return true;
	else
		return false;
}

int main()
{
	stack sta;
	sta.push(10);
	sta.push(12);
	sta.push(14);
	cout<<sta.top()<<endl;
	sta.pop();
	cout<<sta.top()<<endl;
	sta.pop();

	return 0;
}
