#include <iostream>
#include <tuple>

namespace detail
{
	template<typename T, typename U>
	typename std::enable_if<std::is_convertible<T, U>::value || 
	std::is_convertible<U, T>::value, bool>::type
	compare(T t, U u)
	{
		return t == u;
	}
	
	bool compare(...)
	{
		return false;
	}
	
	
	
    template<int I, typename T, typename... Args>
    struct find_index
    {
        static int call(std::tuple<Args...> const& t, T&& val)
        {
            return (std::get<I - 1>(t) == val) ? I - 1 :
                find_index<I - 1, T, Args...>::call(t, std::forward<T>(val));
        }
    };

    template<typename T, typename... Args>
    struct find_index<0, T, Args...>
    {
        static int call(std::tuple<Args...> const& t, T&& val)
        {
            return (std::get<0>(t) == val) ? 0 : -1;
        }
    };
}

template<typename T, typename... Args>
int find_index(std::tuple<Args...> const& t, T&& val)
{
    return detail::find_index<(sizeof...(Args)),  T,  Args...>::call(t, std::forward<T>(val));		//(sizeof...(Args) - 1),
}

int main()
{
    std::tuple<int, int, int, int, double, int> a(2, 3, 1, 4, 5.0, 7);
    std::cout << find_index(a, 1) << std::endl; // Prints 2
    std::cout << find_index(a, 2) << std::endl; // Prints 0
	std::cout << find_index(a, 7) << std::endl; // Prints 5
    std::cout << find_index(a, 5.0) << std::endl; // Prints 4 (not found)
	std::cout << find_index(a, 6) << std::endl; // Prints -1 (not found)
}
