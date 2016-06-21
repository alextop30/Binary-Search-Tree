#include "binTree.h"

template < class T >
class binSTree : public binTree < T >
{
public:
	void insert(const T& x);						// inserts node with value x
	void remove(const T& x);						// removes node with value x
private:
	void insert(Node < T >*&, const T&);					// private version of insert
	void remove(Node < T >*&, const T&);					// private version of remove
	Node < T >* pred(Node < T >*);						// returns predecessor of node
};


//PRIVATE Implementation functions


/*
* Function-- Insert -- private - responsible for inserting nodes in
* to the binary search tree. Function takes in a Node pointner reference
* and a data poitn which is to be inserted into the binary search tree
*
* Insert does not return but it takes node pointer reference and
* a data point to be inserted
*/
template < class T >
void binSTree<T>::insert(Node <T> *&ptr, const T& x)
{
	if (ptr == NULL)							//exit condition is if ptr is equal to NULL
	{
		ptr = new Node<T>(x, NULL, NULL);				//create node to insert

	}
	if (x < ptr->data)							//if value to insert is smaller than
	{									//current node data take left path
		insert(ptr->left, x);
	}
	else if (x> ptr->data)
	{									//if value to inset is higher than
		insert(ptr->right, x);						//current node data take the right path
	}

}


/*
* Function pre- for predecessor - private - responsible for
* finding the predecessor of the node that is passed in
* predecessor is required for removal of the node - remove
* function depends on pred to work
*
* Function returns a pointer to the predecessor of the node
* that is passed in to the function -- the node that is to
* be removed from the tree
*/
template < class T >
Node < T >* binSTree <T>::pred(Node <T> * ptr)
{
	Node<T> * pred = ptr->left;						//take the right pointer from ptr once

	while (pred->right)							//while left is not equal to NULL
	{
		pred = pred->right;						//take all left pointners

	}

	return pred;								//return the predecessor pointer
										//out of the functionn
}


/*
* Function Remove - Private, responsible fo removing an element
* from the binary search tree using the predecessor private funct
* the node is deleted as part of 1 of 3 methods - 1 right child, 1 left
* child or two children -- using predecessor
* function requires predecessor function call
*
* Function does not return but takes in arguments of Node pointer reference
* and a data point which is to be deleted from the tree
*/
template <class T>
void binSTree <T>::remove(Node < T >*& ptr, const T& x)
{
	Node<T> *temp;								//temporary pointer to use in delete

	//search for data to delete

	if (ptr == NULL)
	{
		return;
	}
	if (x < ptr->data)							//looking for the data to be deleted
	{									//if data is lower than the current node
		remove(ptr->left, x);						//take the left pointer
	}
	else if (x > ptr->data)
	{
		remove(ptr->right, x);						//if data is larger than current node
	}									//take the right pointner
	else
	{
		if ((ptr->right == NULL) && (ptr->left ==NULL))			//if a node is a leaf node
		{

			delete ptr;						//delete node - dealocate space
			ptr=NULL;						//set pointer to NULL

		}
		else if (ptr->right == NULL)					//1 child --- in left subtree
		{
			temp = ptr;						//set temp to number to be deleted
			ptr = ptr->left;					//attach left child to parent
			delete temp;						//delete temp pointer (deallocate space)

		}
		else if (ptr->left == NULL)					//1 child --- right subtree
		{
			temp = ptr;						//set temp to number to be deleted
			ptr = ptr->right;					//attach left child to parent
			delete temp;						//delete temp pointer (deallocate space)

		}
		else
		{
			Node<T> * predecessor;					//create a new node and call it predecessor
			predecessor = pred(ptr);				//set predecesser equal to function call to predecessor
			ptr->data = predecessor->data;				//data to be deleted replaced with predecessor's data
			predecessor=NULL;					//set predecessor to zero
			delete predecessor;					//delete predecessor
			remove(ptr->left,ptr->data);				//recursivelly call remove to remove duplicate
										//and link left child up to the parent
		}
	}

}

//PUBLIC MEMBER FUNCTIONS

/*
* Templated function remove- public function used as wrapper
* to call private function takes in argument numbber to be
* removed from the binary search tree
*
* function does not return
*/
template <class T>
void binSTree <T>::remove(const T& x)
{

	remove(this->root, x);							//call private remove with this root
}



/*
* Templated function insert - public function used as wrapper
* to call private function takes in argument number to be
* inserted into the binary search tree
*
* function does not return
*/
template < class T >
void binSTree<T>::insert(const T& x)
{

	insert(this->root, x);							//call private insert with this root
}
