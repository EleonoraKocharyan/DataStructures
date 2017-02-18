#include "stdafx.h"
#include "OA_HashTable.h"
#include <iostream>
using namespace std;

OA_HashTable::OA_HashTable(int size):
size_(size), table_(new Node[size]), hFunction_(new HashFunction())
{
	
}

OA_HashTable::~OA_HashTable(void)
{
	delete []table_; delete hFunction_;
}

bool  
OA_HashTable::search(int key)const
{
	int j=hFunction_->secondFunction(key);
	int k=hFunction_->firstFunction(key)%size_;
	while(table_[k].status_!=FREE)
	{
		if(table_[k].key_==key)
			if(table_[k].status_==DELETED)
				return false;
			else
				return true;
	
		k=(k+j)%size_;
	}
	return false;
}

void  
OA_HashTable::insert(int key)
{
	int i=hFunction_->firstFunction(key);
	int j=hFunction_->secondFunction(key);
	int k=i%size_;
	while(table_[k].status_==OCCUPIED)
	{
		k=(k+j)%size_;
		if(k==i%size_)
		{
			cout<<"no place to insert "<<key<<endl;
			return;
		}
		
	}
	table_[k].key_=key;
	table_[k].status_=OCCUPIED;
}

void  
OA_HashTable::remove(int key)
{
	int i=hFunction_->firstFunction(key);
	int j=hFunction_->secondFunction(key);
	int k=i%size_;
	while(table_[k].key_!=key)
	{
			k=(k+j)%size_;
	}
	table_[k].status_=DELETED;
	
}

void  
OA_HashTable::print()const
{
	for(int i=0; i<size_; i++){
		cout<<"pos="<<i<<": ";
		if(table_[i].status_==OCCUPIED)
			cout<<table_[i].key_<<endl;
		else
			if(table_[i].status_==FREE)
				cout<<"FREE"<<endl;
			else
				cout<<"DELETED"<<endl;
	}
	cout<<endl;
}

