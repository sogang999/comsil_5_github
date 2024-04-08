
#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#include <iostream>
using namespace std;

// LinkedList Node
template <typename T>
class Node {
public:
    // 데이터를 저장할 변수
    T data;
    // 다음 노드의 주소를 저장할 포인터
    Node<T> *link;

    Node(T element) // 노드 생성자 정의
	{
        data = element;
        link = NULL;
    }
};

// LinkedList Class
template <typename T>
class LinkedList 
{
protected:
    
    Node<T> *first; // 첫번째 노드의 주소를 저장할 포인터 멤버변수
    int current_size;// 사이즈 멤버변수 

public:
   
    LinkedList()  // 생성자 생성, 초기화
	{
        first = NULL;
        current_size = 0;
    };

    // 노드 개수를 리턴
    int GetSize() 
	{
        return current_size;
    };

    // 맨 앞에 원소를 삽입
    void Insert(T element);

    // 맨 뒤의 원소를 삭제 ,가상함수로 선언함
    virtual bool Delete(T &element);

    // 리스트 출력
    void Print();
};

// 새 노드를 맨 앞에 붙이고 값을 넣음
template <typename T>
void LinkedList<T>::Insert(T element) // 멤버함수 
 {
    // 노드 생성
    Node<T> *newnode = new Node<T>(element); // 동적으로 할당 받음

    // 새 노드가 첫번째 노드를 가리킴
    newnode->link = first;
    first = newnode;
    current_size++;
}

// 맨 뒤의 원소를 삭제
template <typename T>
bool LinkedList<T>::Delete(T &element) 
{
    if (first == NULL)
        return false;

    Node<T> *current = first;
    Node<T> *previous = NULL;

    // 마지막 노드까지 찾아가는 반복문
    while (current->link != NULL)
	{
        previous = current;
        current = current->link;
    }

    // 마지막 노드를 삭제하고 데이터를 리턴
    element = current->data;
    delete current;
    current_size--;

    // 이전 노드가 nullptr을 가리키게 함
    if (previous != NULL)
        previous->link = NULL;
    else // 모두 삭제될 경우
        first = NULL;

    return true;
} 



// 리스트를 출력하는 Print 함수
template <typename T>
void LinkedList<T>::Print() 
{
    Node<T> *i;
    int index = 1;

    if (current_size != 0) 
	{
        for (i = first; i != NULL; i = i->link) 
		{
            if (index == current_size) 
			{
                cout << "[" << index << "|" << i->data << "]";
            } 
			else 
			{
                cout << "[" << index << "|" << i->data << "]->";
                index++;
            }
        }
        cout << endl;
    }
}
#endif





