#pragma once
#include "HashFunction.h"

//*** REPETITIONS ARE NOT ALLOWED ***//
class OA_HashTable
{
	enum Status{FREE, OCCUPIED, DELETED};

	struct Node{
		int		key_;
		Status	status_;
		Node(int key=0, Status status=FREE):key_(key), status_(status){} 
	};
	
public:
	OA_HashTable(int size);
	~OA_HashTable(void);
	

	/*1*/ bool  search(int key)const;
	
	//precondition: search(key)==false
	/*2*/ void  insert(int key);

	//precondition: search(key)==true
	/*3*/ void  remove(int key);
	
	void  print()const;

private:
	Node*				table_;
	int					size_;		//should be a power of 2
	HashFunction*		hFunction_;
};
