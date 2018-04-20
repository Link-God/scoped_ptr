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

template<typename T>
	scoped_ptr<T>::scoped_ptr(T * ptr )
	{
		ptr_ = ptr;
	}

	template<typename T>
	scoped_ptr<T>::~scoped_ptr()
	{
		delete ptr_;
	}

	template<typename T>
	void scoped_ptr<T>::reset(T * ptr )
	{
		if (ptr_) delete ptr_;
		ptr_ = ptr;
	}

	template<typename T>
	T& scoped_ptr<T>:: operator*() const
	{
		/*if (ptr_)*/ return *ptr_;  // в тестах ббез этих комменттариев выдавал ошибку  
						// из-за того что функция не вегда возвращала значение 
						//control may reach end of non-void function во всех кросе gcc C++ (первые два)
	

	template<typename T>
	T* scoped_ptr<T>::operator->() const
	{
		try {
			if (ptr_) return ptr_;
			else throw 3;
		}
		catch (int)
		{
			std::cerr << "fail ";
		}
	}

	template<typename T>
	T* scoped_ptr<T>::get() const
	{
		return ptr_;
	}

	template<typename T>
	void scoped_ptr<T>::swap(scoped_ptr & other)
	{
		std::swap(ptr_, other.ptr_);
	}
