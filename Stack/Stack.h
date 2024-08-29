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
    Zone<T> *root;
public:
    T& operator[](int i);
    const T operator[](int i) const;
    
    Stack(int size = 1);
    Stack(const Stack &copy);
    ~Stack();
    
    T pop(int i);
    T push(T element);
    T add(T element);
    
};

template <class T>
T& Stack<T>::operator[](int i) {
    if (i < 0) {}
    
    Zone<T> *cur = root;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
        if (cur == NULL) {}
    }
    return cur->memory;
}

template <class T>
const T Stack<T>::operator[](int i) const {
    if (i < 0) {}
    
    Zone<T> *cur = root;
    for (int j = 0; j < i; j++) {
        cur = cur->next;
        if (cur == NULL) {}
    }
    return cur->memory;
}

template <class T>
Stack<T>::Stack(int size) {
    if (size < 1) { }
    
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
    root = new Zone<T>;
    Zone<T> *cur = root;
    Zone<T> *cur_copy = copy.root;
    while (cur_copy != NULL) {
        cur->memory = cur_copy->memory;
        cur->next = new Zone<T>;
        cur_copy = cur_copy->next;
        cur = cur->next;
    }
    cur->next = NULL;
}

template <class T>
Stack<T>::~Stack() {
    Zone<T> *cur = root;
    Zone<T> *next = root->next;
    while (cur->next != NULL) {
        delete cur;
        cur = next;
        if (next->next != NULL) {
            next = next->next;
        }
    }
}

template <class T>
T Stack<T>::pop(int i) {
    if (i < 0) {}
    
    Zone<T> *cur = root;
    
    if (i == 0) {
        root = cur->next;
        T ret = cur->memory;
        delete cur;
        return ret;
    }
    
    for (int j = 0; j < i - 1; j++) {
        cur = cur->next;
        if (cur == NULL) {}
    }
    Zone<T> *next = cur->next->next;
    T ret = cur->next->memory;
    delete cur->next;
    cur->next = next;
    return ret;
}

template <class T>
T Stack<T>::push(T element) {
    
    Zone<T> *temp = root;
    root = new Zone<T>;
    root->next = temp;
    return root->memory = element;
}

template <class T>
T Stack<T>::add(T element) {
    
    Zone<T> *cur = root;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new Zone<T>;
    cur->next->next = NULL;
    return cur->memory = element;
}

#endif /* Stack_h */
