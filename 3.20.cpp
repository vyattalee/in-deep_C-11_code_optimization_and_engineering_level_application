//运行期以索引获取tuple元素-C++11之1
//需支持C++11及以上标准的编译器，VS2017 15.5.x、CodeBlocks 16.01 gcc 7.2
//参见《深入应用C++11:代码优化与工程级应用》p147，祁宇，机械工业出版社，2015年05
#include <iostream>
#include <tuple>

using namespace std;

template <size_t k, typename Tuple> 
typename enable_if<(k == tuple_size<Tuple>::value)>::type
GetArgByIndex(size_t index, Tuple& tp)
{
    throw invalid_argument("arg index out of range");
}

template <size_t k = 0, typename Tuple>
typename enable_if<(k < tuple_size<Tuple>::value)>::type
GetArgByIndex(size_t index, Tuple& tp)
{
    if (k == index)
    {
        cout << get<k>(tp) << endl;
    }
    else
    {
        GetArgByIndex<k + 1>(index, tp);
    }
}

int main()
{
    auto tp = make_tuple(1, 2, 3, 4, "123", "3.20");
    size_t len = tuple_size<decltype(tp)>::value;

    //打印每个元素
    for (size_t i = 0; i < len; ++i)
    { GetArgByIndex(i, tp);    }
	

    GetArgByIndex(5,tp);//out of range
}