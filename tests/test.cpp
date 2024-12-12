#include "test.h"

#include <vector>
#include <functional>
#include <iostream>

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;


// Candle(Price _open, Price _high, Price _low, Price _close);

//tests 2.1
bool test_body_contains1()
{
  Candle candle{ 3.0, 5.0, 2.0, 4.0 };
  Price price{3.5};
  return candle.body_contains(price) == true;
}

bool test_body_contains2()
{
  Candle candle{ 3.0, 5.0, 2.0, 3.0 };
  Price price{3.0};
  return candle.body_contains(price) == true;
}

bool test_body_contains3()
{
  Candle candle{ 4.0, 5.0, 2.0, 3.0 };
  Price price{3.5};
  return candle.body_contains(price) == true;
}

//tests 2.2
bool test_contains1()
{
  Candle candle{ 3.0, 5.0, 2.0, 4.0 };
  Price price{6.5};
  return candle.contains(price) == false;
}

bool test_contains2()
{
  Candle candle{ 3.0, 5.0, 2.0, 4.0 };
  Price price{1.5};
  return candle.contains(price) == false;
}

bool test_contains3()
{
  Candle candle{ 3.0, 5.0, 2.0, 4.0 };
  Price price{3.5};
  return candle.contains(price) == true;
}

//test 2.3
bool test_full_size1()
{
  Candle candle{ 3.0, 5.0, 2.0, 4.0 };
  return candle.full_size() == 3.0;
}

bool test_full_size2()
{
  Candle candle{ 1.0, 2.0, 0.0, 0.0 };
  return candle.full_size() == 2.0;
}

bool test_full_size3()
{
  Candle candle{ 3.0, 3.0, 3.0, 3.0 };
  return candle.full_size() == 0;
}


void initTests()
{
  tests.push_back(test_body_contains1);
  tests.push_back(test_body_contains2);
  tests.push_back(test_body_contains3);
  tests.push_back(test_contains1);
  tests.push_back(test_contains2);
  tests.push_back(test_contains3);
  tests.push_back(test_full_size1);
  tests.push_back(test_full_size2);
  tests.push_back(test_full_size3);



}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}