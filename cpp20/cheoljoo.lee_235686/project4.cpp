#include <iostream>
#include <iterator>
#include <type_traits>
#include <concepts>

template<typename T>
concept Random = requires(T a)
{
	a.c();
};

template<typename T> class Base
{
	public:
		//template<typename T> 
		void foo()
			requires Random<T>
		{
		}

		void goo() {}
};
class A : public Base<A>
{
	public:
		using category = std::random_access_iterator_tag;
		void c(){ return ;}
};
class B : public Base<B>
{
	public:
		using category = std::bidirectional_iterator_tag;
};
int main()
{
	A a;
	B b;
	a.foo(); // ok
	a.goo(); // ok
	b.foo(); // error
	b.goo(); // ok
}


// Instructor comment 수고하셨습니다. void foo() requires std::is_same_v<typename Derived::category,std::random_access_iterator_tag> {} 로 하시면 됩니다. 
