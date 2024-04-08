
#ifndef __STACK_H__
#define __STACK_H__
#include "LinkedList.h"
template <typename T> 
class Stack : public LinkedList<T>
// LinkedList class를 상속받음
{
public:
    bool Delete(T &element)
    {
        // first가 0이면 false 반환
        if (this->first == NULL)// this 포인터 설정 현재 객체에 대한 접근 
            return false;

        // Stack은 current가 가리키는 곳을 삭제
        Node<T> *current = this->first;
        element = current->data;
        this->first = this->first->link;
        this->current_size--;
        delete current;

        return true;
    }
};

#endif