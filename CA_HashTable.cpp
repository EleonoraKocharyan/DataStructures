#include "StdAfx.h"
#include "CA_HashTable.h"
#include <iostream>
using namespace std;

CA_HashTable::CA_HashTable(int size):
size_(size), table_(new Node*[size])
{
	for(int i=0; i<size; i++)
		table_[i]=new Node();
}

CA_HashTable::~CA_HashTable(void)
{
	Node* temp;
	for(int i=0; i<size_; i++)
		while(table_[i]!=0)
		{
			temp=table_[i]; 
			table_[i]=temp->next_;
			delete temp;
		}
	delete []table_;
}

int 
CA_HashTable::hashCode(int key)const
{
	return (10*key) % size_;
}

bool  
CA_HashTable::search(int key)const
{
	Node* curr=table_[hashCode(key)]->next_;
	while(curr)
	{
		if(curr->key_==key)
		return true;
		curr=curr->next_;
	}
	return false;
}

void
CA_HashTable::insert(int key)
{
	Node* curr=table_[hashCode(key)];
	Node* p = new Node(key,curr->next_);
	curr->next_=p;

}

void  
CA_HashTable::remove(int key)
{
	Node* curr=table_[hashCode(key)];
	while(1)
	{
		if(curr->next_->key_==key)
		{
			Node* todel=curr->next_;
			curr->next_=curr->next_->next_;
			delete todel;
			return;
		}
		curr=curr->next_;
	}
	
}
	
void  
CA_HashTable::print()const
{
	Node* current;
	for(int i=0; i<size_; i++)
	{
		cout<<i<<": ";
		for(current=table_[i]; current!=0; current=current->next_)
			cout<<current->key_<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	cout<<"CLOSED ADDRESS HASHING:"<<endl<<endl;
	
	CA_HashTable table(7); //size of table is 7 
	//1; 2; 3; 4; 5; 6; 7; 8; 9; 10
	table.insert(1);
	table.insert(2);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(6);
	table.insert(7);
	table.insert(8);
	table.insert(9);
	table.insert(10);
	table.remove(8);
	table.print();
	
	return 0;
}
