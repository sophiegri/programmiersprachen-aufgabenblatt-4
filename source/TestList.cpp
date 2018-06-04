#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"

//Aufgabe 2

TEST_CASE ("Size of List")
{
    List<int> liste1;
    REQUIRE (liste1.size()== 0);
}

TEST_CASE ("is List empty")
{
    List<int> liste2;
    REQUIRE (liste2.empty()== true);
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
