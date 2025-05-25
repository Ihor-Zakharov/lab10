#pragma once
#include <iostream>
#include <string>

template <typename T>
class Athlete
{
	public:
		std::string name;
		T field;
		static int S;

		Athlete(T field, const std::string& name) : field(field), name(name) {};;

		virtual void Exercise()
		{
			std::cout << "Exercise athlete" << std::endl;
		}

		virtual ~Athlete() 
		{
			std::cout << "Athlete class has been deleted";
		};
};

template <typename T>
class Swimmer : virtual public Athlete<T>
{
	public:
		using Athlete<T>::Athlete; // copying constructors from Athlete class

		void Exercise() override
		{
			std::cout << "Exercise swimmer" << std::endl;
		}

		template<typename... Args>
		void test(const Args&... args)
		{
			(std::cout << ... << args);
		}
};

template<int N>
struct Fibonacci
{
	static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value; // constexpr - computed in compile time when possible
};

template<>
struct Fibonacci<1>
{
	static constexpr int value = 1;
};

template<>
struct Fibonacci<0>
{
	static constexpr int value = 1;
};

template <typename T>
class Runner : virtual public Athlete<T>
{
public:
	using Athlete<T>::Athlete; // copying constructors from Athlete class

	void Exercise() override
	{
		std::cout << "Exercise runner" << std::endl;
	}

	template <int N>
	void test()
	{
		std::cout << Fibonacci<N>::value << std::endl;
	}
};

template <typename T>
class Champion final : public Swimmer<T>, public Runner<T>
{
public:
	Champion(T field, const std::string& name)
		: Athlete<T>(field, name),
		Swimmer<T>(field, name),
		Runner<T>(field, name) {};

	void Exercise() override
	{
		std::cout << "Exercise champion" << std::endl;
	}
};

template <typename T>
int Athlete<T>::S = 5;