#include <iostream>
#include "Athlete.h"

struct A
{

};

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
    Athlete<int> athlete1 = Swimmer<int>(12, "abc");

    std::cout << "Athlete 1 exercise: ";
    athlete1.Exercise();

    Swimmer<int> athlete2 = Swimmer<int>(12, "abc");

    std::cout << "Athlete 2 exercise: ";
    athlete2.Exercise();

    std::cout << "Athlete 2 test (true, false, true): ";
    athlete2.test(true, false, true);
    std::cout << std::endl;

    std::cout << "Athlete 2 test (12, 34, 56, 78): ";
    athlete2.test(12, 34, 56, 78);
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
