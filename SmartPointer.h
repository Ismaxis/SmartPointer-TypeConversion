#pragma once
template <class T>
class SmartPointer
{
public:
    SmartPointer(T* rawPointer = nullptr) : rawPointer(rawPointer), isOwner(true)
    { }

    SmartPointer(SmartPointer& rhs) : rawPointer(rhs.release()), isOwner(true)
    { }

    template <class U>
    SmartPointer(SmartPointer<U>& rhs) : rawPointer(rhs.get()), isOwner(false)
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
        if (isOwner)
        {
            delete rawPointer;
        }
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
        isOwner = false;
        return get();
    }

    T* get()
    {
        return rawPointer;
    }

    void reset(T* newRawPointer)
    {
        if (isOwner && newRawPointer != rawPointer)
        {
            delete rawPointer;
            rawPointer = newRawPointer;
        }
    }

private:
    T* rawPointer;
    bool isOwner;
};
