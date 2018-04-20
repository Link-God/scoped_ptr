#include<iostream>

template<class T>
class scoped_ptr {
private:
	T * ptr_;
public:
	explicit scoped_ptr(T * ptr = 0);
	~scoped_ptr();
	void reset(T * ptr = 0);
	T & operator*() const;
	T * operator->() const;
	T * get() const;
	void swap(scoped_ptr & other);
	scoped_ptr & operator=(scoped_ptr const &) = delete;
	scoped_ptr(scoped_ptr const &) = delete;
};

struct X
{
	int m ;
};
