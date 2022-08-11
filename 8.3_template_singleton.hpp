#include <utility>
#include <iostream>

template <typename T>
class Singleton
{
public:
    template<typename... Args>
    static T* Instance(Args... args)
    {
        if (m_pInstance == nullptr)
        {
            // 完美转发
            m_pInstance = new T(std::forward<Args>(args)...);
        }
        return m_pInstance;
    }
 
    // 获取单例
    static T* GetInstance()
    {
        if (m_pInstance == nullptr) 
        {
            throw std::logic_error("the instance is not init");
        }
        return m_pInstance;
    }
    // 销毁单例
    static void DestroyInstance()
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
 
private:
    Singleton();
    virtual ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator = (const Singleton&);
    static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance = nullptr;

