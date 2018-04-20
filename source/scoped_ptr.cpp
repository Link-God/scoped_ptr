
#include scoped_ptr.hpp

template<typename T>
scoped_ptr::scoped_ptr(T * ptr = 0)
{
	ptr_ = ptr;
}

template<typename T>
scoped_ptr::~scoped_ptr()
{
	delete ptr_;
}

template<typename T>
scoped_ptr::reset(T * ptr = 0)
{
	if (ptr_) delete ptr_;
	ptr_ = ptr;
}

template<typename T>
scoped_ptr:: operator*() const
{
	if (ptr_) return *ptr_;
}

template<typename T>
scoped_ptr::operator->() const
{
	if (ptr_) return ptr_;
}

template<typename T>
scoped_ptr::get() const
{
	return ptr_;
}

template<typename T>
scoped_ptr::swap(scoped_ptr & other)
{
	std::swap(ptr_, other.ptr_);
}
