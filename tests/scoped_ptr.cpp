#include <catch.hpp>
#include <sstream>
#include "scoped_ptr.hpp"

TEST_CASE("Get and *")
{
        scoped_ptr<int> p1(new int(6));
        int * ptr = p1.get();
        scoped_ptr<int> p2(new int(1));
        int k = *p2;
        REQUIRE( *ptr == 6 );
        REQUIRE( k == 1 );
}

TEST_CASE("Swap")
{
        scoped_ptr<int> p1(new int(6));
        scoped_ptr<int> p2(new int(1));
        p1.swap(p2);
        int * ptr = p1.get();
        int k = *p2;
        REQUIRE( *ptr == 1 );
        REQUIRE( k == 6 );
}

TEST_CASE("Reset")
{
        scoped_ptr<int> p1(new int(6));
        p1.reset(new int(5));								 
        int k = *p1;
        REQUIRE( k == 5 );
}
                           
TEST_CASE("->")
{
        scoped_ptr<X> z(new X);
	z->m = 3;
        int k = z->m;
        REQUIRE( k == 3 );
}
