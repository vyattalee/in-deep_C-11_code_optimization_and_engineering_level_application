//运行期以索引获取tuple元素-C++11之2
//需支持C++11及以上标准的编译器，VS2017 15.5.x、CodeBlocks 16.01 gcc 7.2
//参见《深入应用C++11:代码优化与工程级应用》p148，祁宇，机械工业出版社，2015年05
#include <iostream>
#include <tuple>

using namespace std;

template <typename Arg>
void GetArgByIndex(size_t index, tuple<Arg>& tp)
{ cout << get<0>(tp) << endl; }

template <typename Arg, typename... Args>
void GetArgByIndex(size_t index, tuple<Arg, Args...>& tp)
{
    if (index < 0 || index >= tuple_size<tuple<Arg, Args...>>::value)
    { throw invalid_argument("index is not valid");    }

    if (index > 0)
        GetArgByIndex(index - 1, (tuple<Args...>&) tp);
    else    //index == 0
        cout << get<0>(tp) << endl;
}

int main(void)
{
    auto tp = make_tuple(1, 2, "test", 3);
    size_t len = tuple_size<decltype(tp)>::value;

    //打印每个元素
    for (size_t i = 0; i < len; ++i)
    { GetArgByIndex(i, tp);    }

    return 0;
}