#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"

//Aufgabe 4.2

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

// Aufgabe 4.3

TEST_CASE ("add an element with push_front", "[modifiers]")
{
    List<int> list; 
    list.push_front(42);
    REQUIRE (42 == list.front());
}

TEST_CASE ("add an element with push_back", "[modifiers]")
{
    List<int> list; 
    list.push_back(90);
    REQUIRE (90 == list.last());
}

TEST_CASE ("delete first element with pop_front", "[modifiers]")
{
    List<int> list; 
    list.push_front(42);
    list.push_front(50);
    list.pop_front();
    REQUIRE (42 == list.front());
}

TEST_CASE ("delete last element with pop_back", "[modifiers]")
{
    List<int> list; 
    list.push_front(42);
    list.push_front(50);
    list.pop_back();
    REQUIRE (50 == list.front());
}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
