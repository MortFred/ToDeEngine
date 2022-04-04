#include "CppUTest/TestHarness.h"
#include "HelloCpputest.h"
#include "RuntimeErrorStub.h"
#include <stdexcept>

TEST_GROUP(Hello)
{

};

TEST(Hello, AddTwoIntegersReturnsSumOfInput)
{
   uint16_t num1 = 1;
   uint16_t num2 = 2;
   uint16_t sum = AddTwoIntegers(num1, num2);
   UNSIGNED_LONGS_EQUAL(4, sum);
}
