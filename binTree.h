#include "Node.h"

typedef enum { left_side, right_side } SIDE;					//define enumirationtypes Side

/*
* Template class Binary Tree which creates a binary tree
* with the help of the node class - in node.h
*
* Node is inserted randomly left or right based on the
* system executed through rnd function
*/
template < class T > class binTree
{
public:
	binTree();								// default constructor
	unsigned height() const;						// returns height of tree
	virtual void insert(const T&);						// inserts a node in tree
	void inorder(void(*) (const T&));					// inorder traversal of tree
										//  -- pointer to the print function implemented by user
	unsigned size()const;							// public version of size

protected:
	Node < T >* root;							// root of tree
private:
	unsigned height(Node < T >*) const;					// private version of height ( )
	void insert(Node < T >*&, const T&);					// private version of insert ( )
	void inorder(Node < T >*, void(*) (const T&));				// private version of inorder ( )
	unsigned size(Node <T>*)const;						// private version of size

};

//IMPLEMENTATION OF ALL PRIVATE METHODS OF THE BINTREE CLASS

/*
* Private Function implementation Height responcible for finding the
* height of the tree recursivelly. It takes a pointer to a node and
* finds the Height of the tree
*
* Function returns -- unsigned integer out
*/
template < class T >
unsigned binTree<T>::height(Node <T> *ptr) const
{
	if (ptr == NULL)							//if root is nulll you are all the way to the end
	{
		return 0;							//if root is null - count 1 -- return 1
	}

	int left = height(ptr->left);						//take the left path recursivelly
	int right = height(ptr->right);						//take the left path recursivelly

	if (left >= right)							//if left is bigger than right
	{
		return (1 + left);						//return 1+ number of left - account for root

	}
	else
	{
		return (1 + right);						//if right is bigger the left do the same
	}

}
										//random function for taking the
										//different paths left or right
SIDE rnd() { return rand() % 2 ? right_side : left_side; };

/*
* Private Function Insert - inserts an element into the tree
* this function steps through the tree recursivelly and it will
* insert the element randomly in the left or right subtree based
* on rnd -- SIDE function
*
* Function does not return nor print items to the console
*/
template < class T >
void binTree<T>::insert(Node <T> *&ptr, const T& x)
{
	if (ptr == NULL)							//exit condition
	{

		ptr = new Node <T>(x, NULL, NULL);				//assign pointer to a new
										//dynamically allocated instance
										//of the Node class
										//create a new dynamically allocated node
										//use constructor to assign to NULL
	}
	else
	{

		if (rnd()%2 ==0)						//if random is zero left side is taken
		{
			insert(ptr ->left, x);					//call insert function recursivelly passing
										//the data point
		}
		else								//if random is 1 right side is taken
		{
			insert(ptr->right, x);					//call insert function recursivelly passing
										//the data point
		}
	}

}

/*
* Function Inorder Traversal responcible for visiting every node
* in inorder fasion - function also accepts a pointer to a print
* function so that the user can implement Print by themselves
*
* Function will be responcible for printing using the function
* pointer to function print. It also takes a pointer to a node
*/
template < class T >
void binTree<T>::inorder(Node < T >*ptr, void(*Print) (const T& ))
{
	if (ptr != NULL)							//exit condition -- got to a leaf node
	{
		inorder(ptr->left, Print);					//recursive call with left first
										//Print is a required argument of Preorder

		Print(ptr->data);						//Print the data inside the node

		inorder(ptr->right, Print);					//recursive call with the right pointer
										//until it is null - or all the way to the end
	}


}

/*
* Function Binary Tree Size responcible for finding
* the size or number of nodes in the binary tree with
* a recursive call of the left and the right side
* which are added to the root node and returned
*
* Function takes a ponter to a node -- root is passed
* by public version of this function. Returns the size
* of the tree as an unsigned int.
*/
template < class T >
unsigned binTree<T>::size(Node <T>*ptr)const
{
	unsigned int lsize, rsize;

	if (ptr == NULL)							//exit condition on if ptr is NULL
	{
		return 0;
	}
	else
	{
		lsize = size(ptr->left);					//call recursivelly with left pointer
		rsize = size(ptr->right);                       		//call recursivelly with right pointer
	}

	return (1 + lsize + rsize);                        			//return root plus left and right sides

}

//PUBLIC FUNCTION IMPLEMENTATION
/*
* Default constructor of BinTree Class
*
* Creates a tree with root pointer to NULL pointer
* will later will be reasigned to a dynamically allocated
* node - root is passed to most public functions
*
*/
template < class T >
binTree<T>::binTree()								//default constructor
{
	root = NULL;								//set root to NULL
}

/*
* Public Version of Height function wrapper function which
* calls the private function height passing root node
*
*/
template < class T >
unsigned binTree<T>::height() const						//Public Height
{
	return height(root);							//call private height with root ptr
}


/*
* Public Version of Inorder Traversal function wrapper function which
* calls the private function Inorder passing root node and Print function
* pointer which will be responcible for priting the data
*
*/
template < class T >
void binTree<T>::inorder(void (*Print) (const T& x))
{

	inorder(root, Print);							//call private in order with root node
										//and function pointer print
}

/*
* Public Version of Insert function wrapper function which
* calls the private function Insert passing root node and
* data element x as arguments - x is of the same data type
* as the class.
*/
template < class T >
void binTree<T>::insert(const T& x)						//Public Insert
{
		insert(root, x);						//call to private insert with data point
										//to be inserted into the tree
}
/*
* Public version of size serves as a wrapper to get the
* private recursive call started. It passes root to the
* function as the first pointer
*
* Function returns the size of the tree as unsigned int
*/
template < class T >
unsigned binTree<T>::size()const						//public size calls private passing root
{

	return size(root);
}
