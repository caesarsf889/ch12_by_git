//
// Created by caesa on 03/09/2020.
//

#ifndef CH12_5_STACK_ADVANCED_VER_H
#define CH12_5_STACK_ADVANCED_VER_H

template<typename T>
class Stack_advanced{

public:
    Stack_advanced() ;
    Stack_advanced(const Stack_advanced&) ;
    ~Stack_advanced() ;
    bool is_empty()const ;
    T peek()const ;
    void push(T value)  ;
    T pop() ;
    int get_size()const ;


private:
    T* p_element ;
    int size ;
    int capacity ;
    void ensure_capacity() ;


};


template <typename T>
Stack_advanced<T>::Stack_advanced():size(0) ,capacity(16)
{
    p_element = new T[capacity] ;

}

template <typename T>
Stack_advanced<T>::Stack_advanced(const Stack_advanced& stack) {

    p_element = new T[stack.capacity] ;
    this->size = stack.size ;
    this->capacity = stack.capacity ;
    for(int i=0;i <size;i++){

        *(p_element+i) = *(stack.p_element+i) ;

    }


}

template <typename T>
Stack_advanced<T>::~Stack_advanced() {

    delete [] p_element ;

}

template <typename T>
bool Stack_advanced<T>::is_empty() const {


    return size==0 ;
}

template<typename T>
T Stack_advanced<T>::peek() const {


    return  p_element[size-1]  ;
}

template<typename T>
void Stack_advanced<T>::push(T value) {

    ensure_capacity() ;
    p_element[size++] = value ;

}

template <typename T>
void Stack_advanced<T>::ensure_capacity() {

    if(size >= capacity){

        T* p_old_array = p_element ;
        capacity = 2* size ;
        p_element = new T[size * 2] ;

        for(int i=0; i<size ; i++ )
            *(p_element+i) = *(p_old_array+i) ;

        delete [] p_old_array ;

    }


}


template<typename T>
T Stack_advanced<T>::pop() {


    return p_element[--size] ;
}

template<typename T>
int Stack_advanced<T>::get_size() const {



    return size ;
}














#endif //CH12_5_STACK_ADVANCED_VER_H
