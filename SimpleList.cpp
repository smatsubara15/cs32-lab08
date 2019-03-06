#include "SimpleList.h"

template <class T>
SimpleList<T>::SimpleList(){
  numElements=0;
  this->elements= new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList(){
  delete [] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException){
  if(getNumElements()<=index || index<0)
    throw InvalidIndexException();
  else{
    return elements[index];
  }
}

template <class T>
bool SimpleList<T>::empty() const{
  if(numElements==0)
    return true;
  else
    return false;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
  if(getNumElements()==0)
    throw EmptyListException();
  else{
    return elements[0];
  }
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
  if(getNumElements()==0)
    throw EmptyListException();
  else{
    return elements[numElements-1];
  }
}

template <class T>
int SimpleList<T>::getNumElements() const{
  return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
  if(getNumElements()>10)
    throw FullListException();
  else{
    elements[numElements]=item;
    numElements++;
  }
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListEx\
ception){
  if(empty())
    throw EmptyListException();
  if(getNumElements()<=index)
    throw InvalidIndexException();
  else{
    for (int i=index; i<numElements-1; i++){
      elements[i]=elements[i+1];
    }
    numElements--;
  }
}
