#include <iostream>
#include "SmartPointer.h"

class A
{
public:
    virtual ~A() = default;
    virtual void print() const = 0;
};

class B final : public A
{
public:
    void print() const override
    {
        std::cout << "B talking!\n";
    }
};

class C final : public A
{
public:
    void print() const override
    {
        std::cout << "C talking!\n";
    }
};

void print(const SmartPointer<A>& a)
{
    a->print();
}

int main()
{
    SmartPointer<B> b(new B);
    SmartPointer<C> c(new C);

    std::cout << "print(SmartPointer<B>): ";
    print(b);
    std::cout << "print(SmartPointer<C>): ";
    print(c);

    SmartPointer<A> ab(new B);
    SmartPointer<A> ac(new C);

    return 0;
}
