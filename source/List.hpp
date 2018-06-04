#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <list>
#include <iostream>


template <typename T>
class List;
//muss das hier stehen wenn das unten auch schon steht??

template <typename T>
struct ListNode
{
    T value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T>
class ListIterator
{
    public:
    // not implemented yet
    // do not forget about the initialiser lists !
    
    private:
    ListNode <T>* node;
};

template <typename T>
class ListConstIterator
{
    public:
    // not implemented yet
    // do not forget about the initialiser lists !

    private:
    ListNode <T>* node;
};

template <typename T>
class List
{

public:
    using value_type = T;
    using pointer = T*; 
    using const_ponter = T const*;
    using reference = T&;
    using const_reference = T const&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;

// Default Constructor
    List():
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {}

    bool empty() const
    {
       return size_ == 0;        
    }


    std::size_t size() const
    {
        return size_;
    }



private:
    std::size_t size_;
    ListNode <T>* first_; 
    ListNode <T>* last_;

};

#endif


