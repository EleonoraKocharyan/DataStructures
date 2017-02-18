#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{

public:
	Node* left;
		int size_;
	Node* right;
	Node* parent;
	int value;
	
	Node():left(0),right(0),parent(0)
	{
	}
	
	
	Node(int val, Node* p=0, Node* l=0, Node* r=0, int size=0):
	value(val),left(l),right(r),parent(p),size_(size)
	{}
	
	
};
class BinarySearchTree
{
	
public:	
	Node* NIL_;
	
		Node* tree;
	BinarySearchTree(){
	}
	BinarySearchTree(Node* t):tree(t)
	{
		NIL_=new Node(0,0,0,0,0);
	}
void insert(int elem)
{

  Node* current=tree; 
  Node* prev=0;
  while(current!=NIL_)
   {
   		current->size_++;
	  prev=current;
	  current=(elem<current->value)? current->left:current->right;
   }
   current=new Node(elem,prev,NIL_,NIL_,1);
   if (prev==0)
     tree=current;
   else
	 (elem<prev->value)? prev->left=current: prev->right=current;
	 
}

void remove(Node*n)
{
  Node* curr=n;
 
  if(curr==0) return;
  
  Node* next;
  if(curr->left!=NIL_ && curr->right!=NIL_)
  {
	next=curr->right;
	while(next->left!=NIL_)
	next=next->left;
	
	curr->value=next->value;
	curr=next;


  }

  if(curr->left==NIL_)
  {
  	next=curr;
  		while(next->parent)
	{
		next=next->parent;
		--next->size_;
	}

	if(curr->parent)
	{
	if(curr==curr->parent->left)
	
		curr->parent->left=curr->right;
	else
        curr->parent->right=curr->right;
        
			
    }

	else
		tree=curr->right;
		
		if(curr->right!=NIL_)
		curr->right->parent=curr->parent;
	delete curr;
	return; 
  }
  
  if(curr->parent)
  {
	if(curr==curr->parent->left)
        curr->parent->left=curr->left;
	else
		curr->parent->right=curr->left;
		
		next=curr;
  		while(next->parent)
		{
			next=next->parent;
			--next->size_;
		}
	
	}
  	else
	   tree=curr->left;
     curr->left->parent=curr->parent;
   
  	delete curr;
} 
	

Node* select(int i)const
{
	Node* curr=tree;
	while(curr->left->size_+1!=i)
	{
		if(curr->left->size_+1>i)
		curr=curr->left;
		else
		{
			i-=curr->left->size_+1;
			curr=curr->right;
		}
	}
	return curr;
}

int rank(Node* n) const
{
	Node*curr=n;
		int i=curr->left->size_+1;
	
	while(curr->parent)
	{
	
		if(curr==curr->parent->right)	
			i+=curr->parent->left->size_+1;
		
			curr=curr->parent;
		
	}
	return i;
}
	Node* find (int elem)
	{
		Node* curr=tree;
			while(curr)
		{
		
			if(elem>curr->value)
				curr=curr->right;
			else
				if(elem<curr->value)
					curr=curr->left;
			else
				return curr;
		}
		cout<<"no such element found";
		return 0;
	}
};

int main()
{
	Node* t;
	t=new Node(0,0,0,0,0);
	BinarySearchTree* bst = new BinarySearchTree(t);
	bst->insert(6);
	bst->insert(10);
	bst->insert(8);
	bst->insert(11);
	bst->insert(7);
	bst->insert(9);
	bst->insert(3);
	bst->insert(5);
	bst->insert(4);
	bst->insert(1);
	bst->insert(2);	
	bst->remove(bst->find(1));

	cout<<	bst->select(5)->value;
	
	cout<<endl<<bst->rank(bst->find(4));

}












