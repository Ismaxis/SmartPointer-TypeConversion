#pragma once
template <class T>
class SmartPointer
{
public:
    SmartPointer(T* rawPointer = nullptr) : rawPointer(rawPointer)
    { }

    SmartPointer(const SmartPointer& rhs) = delete;

    template <class U>
    // ReSharper disable once CppNonExplicitConvertingConstructor
    SmartPointer(SmartPointer<U>& rhs) : rawPointer(rhs.release())
    { }

    template <class U>
    SmartPointer<T>& operator=(SmartPointer<U>& rhs)
    {
        if (this != &rhs)
        {
            reset(rhs.release());
        }
        return *this;
    }

    ~SmartPointer()
    {
        delete rawPointer;
    }

    T& operator*() const
    {
        return *rawPointer;
    }

    T* operator->() const
    {
        return rawPointer;
    }

    T* release()
    {
        T* released = rawPointer;
        rawPointer = nullptr;
        return released;
    }

    void reset(T* newRawPointer)
    {
        if (newRawPointer != rawPointer)
        {
            delete rawPointer;
            rawPointer = newRawPointer;
        }
    }

private:
    T* rawPointer;
};
