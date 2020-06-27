#define BOOST_TEST_MODULE helloworld_test_module

#include "lib.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE ( hello_test_SUITE )
BOOST_AUTO_TEST_CASE  ( hello_test_CASE  )
{
    BOOST_CHECK(version ()>0);
}
BOOST_AUTO_TEST_SUITE_END()
