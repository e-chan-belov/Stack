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
    T& operator[](int i);
    const T operator[](int i) const;
    
    Stack(int size_ = 1);
    Stack(const Stack &copy);
    ~Stack();
    
    T pop(int i);
    
};

template <class T>
T& Stack<T>::operator[](int i) {
    if (i < 0) {}
    if (i >= size) {}
    
    Zone<T> *cur = root;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
    }
    return cur->memory;
}

template <class T>
const T Stack<T>::operator[](int i) const {
    if (i < 0) {}
    if (i >= size) {}
    
    Zone<T> *cur = root;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
    }
    return cur->memory;
}

template <class T>
Stack<T>::Stack(int size_) {
    if (size_ < 1) { }
    size = size_;
    
    root = new Zone<T>;
    Zone<T> *cur = root;
    for (int _ = 1; _ < size; _++) {
        cur->next = new Zone<T>;
        cur = cur->next;
    }
    cur->next = NULL;
}

template <class T>
Stack<T>::Stack(const Stack &copy) {
    size = copy.size;
    
    root = new Zone<T>;
    Zone<T> *cur = root;
    for (int i = 1; i < size; i++) {
        cur->next = new Zone<T>;
        cur->memory = copy[i - 1];
        cur = cur->next;
    }
    cur->next = NULL;
    cur->memory = copy[size - 1];
}

template <class T>
Stack<T>::~Stack() {
    Zone<T> *cur = root;
    Zone<T> *next = root->next;
    for (int _ = 1; _ < size; _++) {
        delete cur;
        if (next != NULL) {
            cur = next;
            next = next->next;
        }
    }
}

template <class T>
T Stack<T>::pop(int i) {
    if (i < 0) {}
    if (i >= size) {}
    
    Zone<T> *cur = root;
    
    if (i == 0) {
        root = cur->next;
        T ret = cur->memory;
        delete cur;
        return ret;
    }
    
    for (int j = 0; j < i - 1; j++) {
        cur = cur->next;
    }
    Zone<T> *next = cur->next->next;
    T ret = cur->next->memory;
    delete cur->next;
    cur->next = next;
    size--;
    return ret;
}

#endif /* Stack_h */
