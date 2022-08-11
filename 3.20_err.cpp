#include <iostream>
#include <tuple>

using namespace std;


int main()
{
    auto tp = make_tuple(1, 2, 3, 4, "123", "3.20_2");
    size_t len = tuple_size<decltype(tp)>::value;

    //打印每个元素
    for (size_t i = 0; i < len; ++i)	
	
	//error  note: candidate: ‘template<class _Tp, class ... _Types> constexpr _Tp&& std::get(std::tuple<_UTypes ...>&&)’  get(tuple<_Types...>&& __t) noexcept
    //{ cout << get<0>(tp) << endl;    }		
	{ cout << get<static_cast<size_t>(constexpr i)>(tp) << endl;    }		

	return 0;

}