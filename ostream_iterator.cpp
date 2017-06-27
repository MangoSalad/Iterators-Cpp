#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

template <class T, class ch=char,class traits=char_traits<ch>>
class my_ostream_iterator {
	private:
		basic_ostream<ch,traits>* out;
		const ch *delimiter;
	public:
		typedef ch char_type;
  		typedef traits traits_type;
 		typedef basic_ostream<ch,traits> ostream_type;
		//default constructor
		my_ostream_iterator(ostream_type& s) : out(&s), delimiter(0) {}
		//constructors
	  	my_ostream_iterator(ostream_type& s, const ch* delim)
	    : out(&s), delimiter(delim) { }
	  	my_ostream_iterator(const  my_ostream_iterator<T,ch,traits>& x)
	    : out(x.out), delimiter(x.delimiter) {}
		
		//copy constructor
		my_ostream_iterator(const T &S) {}

		//destructor
		~my_ostream_iterator() {}

		//assignment operator
		my_ostream_iterator<T,ch,traits>& operator= (const T& value) 
		{
		    *out << value;
		    if (delimiter!=0) 
		    	*out << delimiter;
		    return *this;
  		}

		//* operator
		my_ostream_iterator<T,ch,traits>& operator*() { return *this; }
		//++ operator
	 	my_ostream_iterator<T,ch,traits>& operator++() { return *this; }
	 	//++(int) operator
	  	my_ostream_iterator<T,ch,traits>& operator++(int) { return *this; }
};

int main()
{
	vector<int> v= {9,1,5,6,4};
	my_ostream_iterator<int> out_it (std::cout," ");
 	copy ( v.begin(), v.end(), out_it);
 	cout<<"\n";
  	return 0;
}