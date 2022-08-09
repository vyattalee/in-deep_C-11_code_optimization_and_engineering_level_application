
//测试代码:
#include "template_singleton.hpp"
#include <iostream>
#include <string>
using namespace std;
 
struct A
{
    A(const string& s) { cout << "A::lvalue:" << s << endl; };
    A(string&& x) { cout << "A::rvalue:" << x << endl; };
};
struct B
{
    B(const string& s) { cout << "B::lvalue:" << s << endl; };
    B(string&& x) { cout << "B::rvalue:" << x << endl; };
};
struct C
{
    C(int x, int y) {}
    void Fun() { cout << "test" << endl; }
};
 
int main()
{
    const string str = "xxx";
//  Singleton<A>::Instance("hello");
    Singleton<A>::Instance(str);
    Singleton<B>::Instance(std::move(str));
    Singleton<C>::Instance(1, 2);
    Singleton<C>::GetInstance()->Fun();
 
    Singleton<A>::DestroyInstance();
    Singleton<B>::DestroyInstance();
    Singleton<C>::DestroyInstance();
 
    return 0;
}

