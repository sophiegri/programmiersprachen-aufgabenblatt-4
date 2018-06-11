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

// Aufgabe 4.4 

TEST_CASE ("should be empty after clearing", "[modifiers]")
{
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.clear();
    REQUIRE (list.empty());
}


// Aufgabe 4.6 

TEST_CASE ("should be an empty range after default construction", "[iterators]")
{
    List<int> list;
    auto b = list.begin();
    auto e = list.end();
    REQUIRE (b == e);
}

TEST_CASE ("provide access to the first element with begin", "[iterators")
{
    List<int> list;
    list.push_front(42);
    REQUIRE(42 == *list.begin());
} 

// Aufgabe 4.7 

TEST_CASE ("compare two lists with different size" , "[modifiers]")
{
    List<int> list1;
    List<int> list2;
    list1.push_front(42);    
    REQUIRE(list1 != list2);
} 

TEST_CASE ("compare two Lists with same size" , "[modifiers]")
{
    List<int> list1;
    List<int> list2;
    list1.push_front(42);  
    list2.push_front(42);   
    REQUIRE(list1 == list2);
} 

// Aufgabe 4.8 

TEST_CASE ("copy constructor", "[constructor]")
{
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2{list};
    REQUIRE(list == list2);
}

// Aufgabe 4.10

/* TEST_CASE ("reversed lists 1", "[reverse]")
{
    List<int> list1; 
    list1.push_front(1);
    list1.push_front(2);
    list1.push_front(3);
    list1.push_front(4);
    list1.reverse();
    REQUIRE(1 == list1.front());
    REQUIRE(4 == list1.last());

    List<int> list2;
    list2.push_back(4);
    list2.reverse(); 
    REQUIRE(4 == list2.front());
}

TEST_CASE ("reversed lists 2", "[reverse]")
{
    List<int> list1; 
    list1.push_back(9);
    list1.push_front(23);
    list1.push_back(98);
    List<int> list2; 
    reverse(list2);
    REQUIRE(98 == reverse(list1).front());
    REQUIRE(list2.begin() == nullptr);
} */

// Aufgabe 4.11

/* TEST_CASE ("copy list in vector", "[copy list]")
{
    List<int> list; 
    std::vector<int> v1; 
    list.push_front(2); 
    std::copy (list.begin(), list.end(), v1.begin());
    REQUIRE(2 == *v1.begin());
} */


// Aufgabe 4.13 

/* TEST_CASE ("move constructor", "[constructor]")
{
    List<int> list; 
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    List<int> list2 = std::move(list);
    REQUIRE(0 == list.size());
    REQUIRE(list.empty());
    REQUIRE(4 == list2.size());
} */



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);

}
