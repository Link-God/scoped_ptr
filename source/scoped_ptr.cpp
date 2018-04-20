
#include scoped_ptr.hpp
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
	T & scoped_ptr<T>:: operator*() const
	{
		if (ptr_) return *ptr_;
	}

	template<typename T>
	T * scoped_ptr<T>::operator->() const
	{
		if (ptr_) return ptr_;
	}

	template<typename T>
	T * scoped_ptr<T>::get() const
	{
		return ptr_;
	}

	template<typename T>
	void scoped_ptr<T>::swap(scoped_ptr & other)
	{
		std::swap(ptr_, other.ptr_);
	}
