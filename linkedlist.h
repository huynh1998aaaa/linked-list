#ifndef LINKEDLIST
#define NODE
#include <iostream>
using namespace std;
#include "node.h"
template <class T>
class linkedlist
{

	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	/*linkedlist(){
		this->head=NULL;
		this->tail=NULL;
	}*/
	void pushfront(T data){
		Node<T> *newnode = new Node<T> *(data);
		if(isempty()){
			this->head=newnode;
			this->tail=newnode;
		}
		else{
			newnode->next=head;
			this->head=newnode;
		}
		this->size++;
	}
	void popfront()
	{
		if(isempty())
			return false;
		else
		{
			if(this->head ==this->tail){
				delete this->head;
				this->head==NULL;
				this->tail==NULL;
			}
			else{


			Node<T> *temp=head;
			head=head->next;
			delete temp;
			}
		}
	}
	T topfront() const
	{
		return this->head->newnode;
	}
	void pushback(T data){
		Node<T> *newnode =new Node<T> (data);
		if(isempty())
		{
			this->head=newnode;
			this->tail=newnode;
		}
		else
		{
			this->tail->next=newnode;
			this->tail=newnode;
		}
		this->size++;
	}
	T topback() const
	{
		return this-> tail->newnode;
	}
	void popback(){
		Node<T> *temp= head;
		if(isempty())
			return false;
		else{
			if(this->head==this->tail)
			{
				delete this->head;
				this->haed=NULL;
				this->tail=NULL;
			}
		else{


		while(temp->next->next!= NULL)
		{
			temp=temp->next;
		}
		this->tail=temp;
		delete temp;
		temp->next=NULL;
		}
	}
	}
	void insert(){
		
	}
	bool isempty(){
		return this->head==NULL;
	}
	int Size() const
	{
		return size;
	}
};
T operator [](int id){
		Node<T>* prev;
		if( id < size )
			prev = find(id);
		return prev->val;
	}
#endif
