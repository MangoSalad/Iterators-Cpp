#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

template<class T,class charT=char,class traits=char_traits<charT>,class Distance=ptrdiff_t>
class my_istream_iterator
{
	private:
		basic_istream<charT,traits> *in;
		T value;
	public:
		typedef charT charType;
		typedef traits traits_Type;
		typedef basic_istream<charT,traits> istream_type;
		//default constructor
		my_istream_iterator():in(0){}
		//constructors
		my_istream_iterator(istream_type& s) : in(&s) { ++*this; }
		my_istream_iterator(const my_istream_iterator<T,Distance>& s):in(s.is),value(s.value) {}

		//copy constructor
		my_istream_iterator(const T &S) {}

		//destructor
		~my_istream_iterator(){}

		//* operator
		const T& operator*() const 
		{ 
			return value; 
		}
		//-> operator
		const T* operator->() const 
		{ 
			return &value; 
		}
		//++ operator
		my_istream_iterator<T,charT,traits,Distance>& operator++() 
		{
		    if (in && !(*in >> value)) in=0;
		    return *this;
		}
		//++ (int) operator
		my_istream_iterator<T,charT,traits,Distance> operator++(int) 
		{
		    my_istream_iterator<T,charT,traits,Distance> tmp = *this;
		    ++*this;
		    return tmp;
		}
};

//== operator
template <class T, class Distance>
bool  operator==(const my_istream_iterator<T, Distance> &x, const my_istream_iterator<T, Distance> &y)
{
	return *x==*y;
}
//!= operator
template <class T, class Distance>
bool  operator!=(const my_istream_iterator<T, Distance> &x, const my_istream_iterator<T, Distance> &y)
{
	return*x!=*y;
}

int main ()
{
	double value1, value2;
	std::cout << "Please, insert two values: ";

	my_istream_iterator<double> eos;              
	my_istream_iterator<double> iit (std::cin);   
	if (iit!=eos) value1=*iit;
	++iit;
	if (iit!=eos) value2=*iit;
	cout << value1 << "+" << value2 << "=" << (value1+value2) << '\n';

	return 0;
}