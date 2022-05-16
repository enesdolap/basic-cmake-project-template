#include <gtest/gtest.h>

#include "example/example.h"

unsigned int Factorial(unsigned int number)// NOLINT(misc-no-recursion)
{
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST(Factorial, FactorialWithoutConstexpr)
{
  EXPECT_EQ(Factorial(1), 1);
  EXPECT_EQ(Factorial(2), 2);
  EXPECT_EQ(Factorial(3), 6);
  EXPECT_EQ(Factorial(10), 3628800);
}

class ExampleClassTest : public ::testing::Test
{
protected:
  /* data */
  void SetUp() override {

  }

  void TearDown() override {

  }

  example factoria_ex;
};


TEST_F(ExampleClassTest, ExampleClassFactorialExample)
{
  EXPECT_EQ(factoria_ex.factorial(1), 1);
  EXPECT_EQ(factoria_ex.factorial(2), 2);
  EXPECT_EQ(factoria_ex.factorial(3), 6);
  EXPECT_EQ(factoria_ex.factorial(10), 3628800);
}
