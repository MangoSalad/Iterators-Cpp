#include <iostream>
#include <iterator>     
#include <vector>        
#include <deque>  
#include <algorithm>    
using namespace std;

template <class Cont>
class my_front_iterator{
	private:
		Cont *C; 
	public:
		typedef Cont container_type;
		//default constructor
		my_front_iterator(Cont &X):C(&X){}
		//assignment operator
		my_front_iterator<Cont>& operator= (const typename Cont::value_type& value)
   		{ 
   			C->push_front(value); return *this; 
   		}
   		//assignment operator w/move assignment
	    my_front_iterator<Cont>& operator= (typename Cont::value_type&& value)
    	{ 
    		C->push_front(std::move(value)); return *this; 
    	}
    	//* operator
	    my_front_iterator<Cont>& operator*() { return *this;}
	    //++ operator
	    my_front_iterator<Cont>& operator++() { return *this;}
	    //++(int) operator
	    my_front_iterator<Cont>& operator++ (int) { return *this;}

};

//global inserter func
template<class Cont>
my_front_iterator<Cont> my_front_inserter(Cont &X) {
    return my_front_iterator<Cont>(X);
}


int main()
{
	deque<int> v= {9,1,5,6,4};
	deque<int> s;
	//my_front_iterator<deque<int>> front_it (s);
	copy(v.begin(),v.end(),my_front_inserter(s));
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout<<"\n";
}