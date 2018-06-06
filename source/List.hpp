#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <list>
#include <iostream>


template <typename T> class List;

template <typename T> struct ListNode 
{
    T value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

template <typename T> class ListIterator
{
    public:
    // not implemented yet
    // do not forget about the initialiser lists !
    
    private:
    ListNode <T>* node;
};

template <typename T> class ListConstIterator
{
    public:
    // not implemented yet
    // do not forget about the initialiser lists !

    private:
    ListNode <T>* node;
};

template <typename T> class List
{
    public:
    using value_type = T;
    using pointer = T*; 
    using const_ponter = T const*;
    using reference = T&;
    using const_reference = T const&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;

// Aufgabe 4.2

    List(): size_{0}, first_{nullptr}, last_{nullptr} {} //Default Constructor
    bool empty() const {return size_ == 0;}
    std::size_t size() const{return size_;}

// Aufgabe 4.3 
    
    T& front() const {return first_->value;}
    T& last() const {return last_->value;}

    void push_front(T const& value) //new_value ist eine Referenz auf ein kostantes T-Objekt
    //das Methoden-const verspricht, dass der Zustand des Objekts auf dem die Methode aufgerufen wird nicht verändert wird
    { 
        ListNode <T>* nodepointer = new ListNode<T> {value, nullptr, nullptr} ; //immer gleich initialisieren 
        //new gibt Adresse, dynamischen Speicher und ruft Konstruktor auf
        //ein dynamisches Objekt ListNode erstellt mit Aggregatinitalisierung 

        if (!empty())  
        {
            first_->prev = nodepointer;
            nodepointer->next = first_;             
        } 
        else 
        {
            last_=nodepointer; //falls die Liste leer war zeigen nun beide Pointer auf Null
        }

        first_ = nodepointer; 
        ++size_;
    }

    void push_back (T const& value)
    {
        ListNode <T>* nodepointer = new ListNode<T> {value, nullptr, nullptr} ;

        if (!empty())
        {
            last_->next = nodepointer; 
            nodepointer->prev = last_; 
        }
        else 
        { 
            first_=nodepointer;              
        }

        last_ = nodepointer; 
        ++size_;
    }

    void pop_front ()
    {
        if (true == empty() )
        {
            std::cout << "Die Liste enthält keine Elemente!" << "\n";
        }

        else if (1 == size_)
        {
            delete first_; 
            first_ = nullptr; 
            last_ = first_; 
            --size_;
        }

        else 
        {
            auto temp_first = first_->next;
            delete first_; 
            first_ = temp_first;    
            first_->prev = nullptr; 
            --size_; 
        }
    }

    void pop_back ()
    {
        if (true == empty() )
        {
            std::cout << "Die Liste enthält keine Elemente!" << "\n";
        }

        else if (1 == size_)
        {
            delete last_; 
            last_ = nullptr; 
            first_ = last_; 
            --size_;
        }

        else 
        {
            auto temp_last = last_->prev;
            delete last_; 
            last_ = temp_last;    
            last_->next = nullptr; 
            --size_; 
        }
    }





    private:
    std::size_t size_;
    ListNode <T>* first_; 
    ListNode <T>* last_;
};

#endif


