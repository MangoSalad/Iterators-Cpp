#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <class Cont>
class my_back_iterator{
	private:
		Cont *C; 
		typename Cont::iterator it;	//qualified pipe
	public:
		typedef Cont val;
		//constructor
		my_back_iterator(Cont &X):C(&X){}
		//assignment operator
	    my_back_iterator<Cont> & operator=(typename Cont::const_reference val) 
	    {
	        C->push_back(val);
	        return *this;
	    }
	    //* operator
	    my_back_iterator<Cont>& operator*() { return *this;}
	    //++ operator
	    my_back_iterator<Cont>& operator++() { return *this;}
	    //++(int) operator
 	    my_back_iterator<Cont>& operator++ (int) { return *this;}

};

//global back inserter func
template<class Cont>
my_back_iterator<Cont> my_back_inserter(Cont &X) {
    return my_back_iterator<Cont>(X);
}

int main()
{
	vector<int> v= {9,1,5,6,4};
	vector<int> s;
	copy(v.begin(),v.end(),my_back_inserter(s));
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout<<"\n";
}