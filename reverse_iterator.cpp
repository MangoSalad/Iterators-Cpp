#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

//template <class T, class ch=char,class traits=char_traits<ch>>
template <class iter,class traits=iterator_traits<iter>>
class my_reverse_iterator
{
	private:
		iter it;
		//typedef iter& reference;
    public:
    	typedef traits iterator_category;
        typedef traits value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::pointer pointer;
        typedef typename traits::reference reference;

        typedef iter iterator_type;
        //typedef my_reverse_iterator<iter> self;

    	//default constructor
    	my_reverse_iterator(): it() { }
    	//constructor with iter argument
	    my_reverse_iterator(iter x): it(x) { }
	    //copy constructor
	    my_reverse_iterator(const my_reverse_iterator &x) {}

	    //assignment operator
	 	my_reverse_iterator<iter>& operator= (const iter& x) 
		{
		    it=x;
		    return *this;
  		}

	    //member func base()
	    iter base() const
	    {
	    	return it;
	    }

	    //* operator
	    reference operator*() const
	    {
	    	iterator_type temp=base();
	    	--temp;
	    	return *temp;
	    }
	    //-> operator
		reference operator->() const
	    {
	    	return &(operator*());
	    }

	    //++(int) operator
	    my_reverse_iterator& operator++(int)
	    { 
	    	it--; 
	    	return *this; 
	    }
	    //++ operator
	    my_reverse_iterator& operator++()
	    { 
	    	it--; 
	    	return *this; 
	    }
	 	//--(int) operator
	    my_reverse_iterator& operator--(int)
	    { 
	    	it++; 
	    	return *this; 
	    }
	    //-- operator
	    my_reverse_iterator& operator--()
	    { 
	    	it++; 
	    	return *this; 
	    }
	    //+= operator
	    my_reverse_iterator& operator+=(difference_type n)
	    { 
	    	it-=n;
	    	return *this;
	    	//return &it; 
	    }
	    //-= operator
	    my_reverse_iterator& operator-=(difference_type n)
	    { 
	    	it+=n;
	    	//return &it; 
	    	return *this;
	    }
};

//+ operator
template <typename iter>
my_reverse_iterator<iter>
operator+(typename my_reverse_iterator<iter>::difference_type n, const my_reverse_iterator<iter>& ri)
{
    return ri+n;
}
//- operator
template <typename iter>
typename my_reverse_iterator<iter>::difference_type operator-(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
    return y.base() - x.base();
}

//== operator
template <typename iter>
bool  operator==(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()==y.base();
}
//!= operator
template <typename iter>
bool  operator!=(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()!=y.base();
}
//< operator
template <typename iter>
bool  operator<(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()<y.base();
}
//<= operator
template <typename iter>
bool  operator<=(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()<=y.base();
}
//> operator
template <typename iter>
bool  operator>(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()>y.base();
}
//>= operator
template <typename iter>
bool  operator>=(const my_reverse_iterator<iter> &x, const my_reverse_iterator<iter> &y)
{
	return x.base()>=y.base();
}


int main()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(2);
	vector<int>::iterator it;
	it = v.begin();
	
	my_reverse_iterator<vector<int>::iterator> p;
	my_reverse_iterator<vector<int>::iterator> q (it);
	q-=2;
	cout<<&q<<endl;
	cout<<*q<<endl;
}