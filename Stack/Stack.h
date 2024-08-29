#ifndef Stack_h
#define Stack_h

template <class T>
class Zone {
public:
    Zone *next;
    T memory;
};

template <class T>
class Stack {
private:
    int size;
    Zone<T> *root;
public:
    Stack(int size_ = 1);
    
};

template <class T>
Stack<T>::Stack(int size_) : size(size_)  {
    if (size_ < 1) { }
    root = new Zone<T>;
    Zone<T> *cur = root;
    for (int i = 1; i < size; i++) {
        cur->next = new Zone<T>;
        cur = cur->next;
    }
    cur->next = NULL;
}


#endif /* Stack_h */
