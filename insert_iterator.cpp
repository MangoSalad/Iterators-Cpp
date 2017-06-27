#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

template <class Cont>
class my_iterator{
	private:
		Cont *C; 
		typename Cont::iterator it;	//qualified pipe
	public:
		//constructor takes arguments of type Cont and iterator 
		my_iterator(Cont &X, typename Cont::iterator i):C(&X), it(i) {}
		//assignment operator
	    my_iterator<Cont> & operator=(typename Cont::const_reference val) 
	    {
	        it = C->insert(it, val);
	        ++it;
	        return *this;
	    }
	    //* operator 
	    my_iterator<Cont>& operator*() { return *this;}
	    //++ operator
	    my_iterator<Cont>& operator++() { return *this;}
	    //++(int) operator
	    my_iterator<Cont>& operator++ (int) { return *this;}

};

//global function inserter()
template<class Cont, class It>
my_iterator<Cont> my_inserter(Cont &X, It i) {
    return my_iterator<Cont>(X, typename Cont::iterator(i));
}

int main()
{
	vector<int> v= {9,1,5,6,4};
	vector<int> s;
	copy(v.begin(),v.end(),my_inserter(s,s.begin()));
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout<<"\n";
}