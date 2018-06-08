#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <list>
#include <iostream>


template <typename T> class List; //man kann es erstmal nutzen, obwohl noch keine Funtkionen da sind etc. 

template <typename T> struct ListNode 
{
    T value = T();
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
};

// Aufgabe 4.5 

template <typename T> class ListIterator
{
    public:
    using Self = ListIterator <T>;
    using value_type = T; 
    using pointer = T*; 
    using reference = T&; 
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    
    ListIterator(): //Standardkonstruktor
    node {nullptr}
    {}

    ListIterator(ListNode<T>* n): 
    node {n} 
    {}
    

    reference operator* () const 
    {
        return node->value; //Gibt den Wert des node zurück
    } 
    
    pointer operator->() const 
    {
        return &(node->value); //Die Referenz gibt die Adresse des Wertes zurück
    } 
    

    Self& operator++() //Iterator weitersetzen (++x)
    {        
        node = node->next; 
        return *this;  //so wird der Iterator zurückgegeben 
    } 


    Self operator++(int) //Der Iterator wird eins weitergesetzt, es wird aber die vorherige Position ausgegeben (x++)
    {
        Self old = *this; //unser neuer Iterator ist auf dem alten Iterator
        ++(*this); //erhöhe die Position des Iterators um 1 
        return old; //gib mir die alte Position zurück
    } 

     ListNode <T>* get_node () const //get Methode um an den Wert eines neuen Iterators zu kommen
    {
        return node;
    }

    bool operator==(Self const& x) const //vergleicht die Positionen zwei Iteratoren miteinander
    {
        return node == x.get_node();
        
    } 


    bool operator!=(Self const& x) const //schaut ob zwei Iteratoren ungleich sind
    {
        return node != x.get_node();
        
    }


    Self next () const //Gibt einen Iterator zurück, der auf das nächste Element zeigt
    {
        if (node)
        {
            return ListIterator(node->next);
        }
        else
            return ListIterator (nullptr);
    }   


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
    using const_pointer = T const*;
    using reference = T&;
    using const_reference = T const&;
    using iterator = ListIterator<T>;
    using const_iterator = ListConstIterator<T>;

// Aufgabe 4.2

    //Default Constructor
    List(): 
    size_{0}, 
    first_{nullptr}, 
    last_{nullptr} 
    {} 

    //Copy Constructor
    List(List<T> const& list):
    size_{0},
    first_{nullptr},
    last_{nullptr}
    {
        for (auto c = list.begin(); c != nullptr; ++c) 
        {
            push_back(*c);
        }
    }

    //Destruktor
    ~List() 
    {
        clear();
    }
    
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
            last_ = nodepointer; //falls die Liste leer war zeigen nun beide Pointer auf Null
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
            std::cout << "The list is already empty!" << "\n";
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

// Aufgabe 4.4 

    void clear ()
    {
        if (true == empty()) 
        {
            std::cout << "There are no elements in the list." << "\n"; 
        }
        while (size_ != 0)
        {
            pop_back();
        }             
    }

// Aufgabe 4.6 

    iterator begin () const //gibt einen ListIterator auf den ersten Knoten zurück
    {
        return iterator(first_);   
    }

    iterator end () const //gibt einen ListIterator auf das Ende (nullptr, Standardkonstruktor) zurück
    {
        return iterator();
    } 

// Aufgabe 4.9 

    void insert (ListIterator<T> const& position, T const& value)
    {
        auto m = position.get_node();

        if (m->prev == nullptr) //Wenn m mein erstes Element ist, dann füge den Wert am Ende ein
        {
            push_front(value);
        }
        else if (m == nullptr) //das kann zutreffen wenn m auf das Ende der Liste zeigt oder die Liste leer ist
        {
            push_back(value);
        }
        //um einen Knoten irgendwo einzufügen müssen wir einen neuen ListNode definieren
        else 
        {
            ListNode <T>* new_node = new ListNode<T> {value, m->prev, m}; 
            //der Wert unseres neuen nodes ist die eingabe value, die prev Position ist m->prev und next ist m weil es ja davor eingefügt werden soll
            m->prev->next = new_node; // das vorherige prev von m ist jetzt next new_node 
            m->prev = new_node;
        }
        ++size_; //erhöhe die Größe mit jedem insert 
    }
// Aufgabe 4.10 

    void reverse()
    {
        List<T> help_list; //neue Liste anlegen

        for (auto p = begin(); p != nullptr; ++p) //es werden die Elemente aus der Liste in die neue Liste eingefügt
        {
            help_list.push_back(*p);
        }
        clear(); //die Liste wird geleert

        for (auto p = help_list.begin(); p != nullptr; ++p) //die Elemente die in der neuen Liste gespeichert wurden werden in die Liste umgekehrt (push_back) eingefügt
        {
            push_front(*p);
        }
    }

    private:
    std::size_t size_;
    ListNode <T>* first_; 
    ListNode <T>* last_;
};

// Aufgabe 4.7 

template <typename T> 
bool operator == (List<T> const& xs, List<T> const& ys)
{
    if (xs.size() != ys.size()) //wenn die Größe nicht gleich ist, sind die Listen nicht gleich 
    {
        return false; 
    }
    else 
    {
        auto x = xs.begin(); 
        auto y = ys.begin(); 

        while (x != nullptr) //solange bis X auf einen nullptr zeigt, also am Ende der Liste ist  
        {
            if (*x != *y) //prüfe ob der Wert vom Knoten x und y gleich ist
            {
                return false; //wenn der Wert nicht gleich ist, sind die Listen nicht gleich 
            }
        ++x; //gehe einen Knoten weiter und wiederhole die Schleife 
        ++y;
        }
        return true; //Falls das Ende also ein nullptr erreicht ist, und alle Werte gleich waren, sind die Listen gleich
    }
}

template <typename T>
bool operator != (List<T> const& xs, List<T> const& ys)
{
    return !(xs==ys); //Gegenteil vom == Operator 
}

template <typename T>
List<T> reverse(List<T> const& list)
{
    List<T> reversed_list; 

    for (auto p = list.begin(); p != nullptr; ++p)
    {
        reversed_list.push_front(*p);
    }
    return reversed_list; 
}


#endif


