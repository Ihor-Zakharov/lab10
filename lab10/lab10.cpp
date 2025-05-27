#include <iostream>
#include "Athlete.h"

struct A {};

struct B
{
    void b() {};
};

struct C
{
    virtual void b() {};
};

int main() 
{
    Swimmer<int> swimmer = Swimmer<int>(12, "abc");
    Athlete<int> athlete = swimmer; // if reference is being used, derived methods are called

    std::cout << "Athlete exercise: ";
    athlete.Exercise();

    std::cout << "Athlete type: " << typeid(athlete).name() << std::endl;

    std::cout << "Swimmer exercise: ";
    swimmer.Exercise();

    std::cout << "Swimmer test (true, false, true): ";
    swimmer.test(true, false, true);
    std::cout << std::endl;

    std::cout << "Swimmer test (12, 34, 56, 78): ";
    swimmer.test(12, 34, 56, 78);
    std::cout << std::endl;

    Runner<int> runner = Runner<int>(12, "abc");
    runner.test<5>();

    std::cout << "sizeof A: " << sizeof(A) << std::endl;
    std::cout << "sizeof B: " << sizeof(B) << std::endl; 
    std::cout << "sizeof C: " << sizeof(C) << std::endl; // class info link

    
    Champion<std::string>* champion = new Champion<std::string>("abc", "cba");
    champion->Exercise();

    return 0;
}
