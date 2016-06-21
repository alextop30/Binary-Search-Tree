#include "binSTree.h"

#define SEED1    1 // seed for 1st RNG
#define SEED2   31 // seed for 2nd RNG

#define N1      50 // size of 1st vector
#define N2     100 // size of 2nd vector
#define R     1000 // high val for rand integer

#define LSIZE   20 // no of vals printed on line
#define ITEM_W   4 // no of spaces for each item

unsigned sz;       // size of tree

// class to generate rand ints
class RND {
private:
    int seed, high;
public:
    RND ( const int& s = 1, const int& h = 1 ) : seed ( s ), high ( h )
        { srand ( seed ); }
    int operator ( ) ( ) const { return rand ( ) % ( high + 1 ); }
};

// prints out val passed as argument
template < class T > void print ( const T& x ) {
    static unsigned cnt = 0;
    cout << setw ( ITEM_W ) << x << ' '; cnt++;
    if ( cnt % LSIZE == 0 || cnt == sz ) cout << endl; 
    if ( cnt == sz ) cnt = 0;
}

// prints out size and height of bin search tree and
// data val in each node in sorted order
template < class T > void print_vals ( binSTree < T >& tree )
{
    // print size and height of tree
    sz = tree.size ( ); unsigned ht = tree.height ( );
    cout << "size of tree   = " << sz << endl;
    cout << "height of tree = " << ht << endl << endl;

    // print data values of tree in sorted order
    tree.inorder ( print ); cout << endl;
}

// driver program: to test several member functions
// of bin search tree class

int main ( )
{
    // create 1st vector and fill it with rand ints
    vector < int > v1 ( N1 );
    generate ( v1.begin ( ), v1.end ( ), RND ( SEED1, R ) );

    // create 2nd vector and fill it with rand ints
    vector < int > v2 ( N2 );
    generate ( v2.begin ( ), v2.end ( ), RND ( SEED2, R ) );

    // create bin search tree with int vals in 1st vector
    binSTree < int > tree;
    for (unsigned i = 0; i < v1.size ( ); i++)
        tree.insert ( v1 [ i ] );

    // print vals of bin search tree before removals
    cout << "Values of bin search tree before removals\n";
    cout << "-----------------------------------------\n\n";
    print_vals ( tree );

    // print vals of 2nd vector in sorted order and
    // deleting duplicate vals

    cout << "Values in 2nd vector in sorted order\n";
    cout << "------------------------------------\n\n";
    vector < int > v3 = v2; sort ( v3.begin ( ), v3.end ( ) );
    auto p = unique ( v3.begin ( ), v3.end ( ) );
    v3.resize ( p - v3.begin ( ) ); sz = v3.size ( );
    for_each ( v3.cbegin ( ), v3.cend ( ), print < int > );
    cout << endl;

    // delete vals in 2nd vector from binary search tree
    for ( unsigned i = 0; i < v2.size ( ); i++ )
        tree.remove ( v2 [ i ] );

    // print vals of bin search tree after removals
    cout << "Values of bin search tree after removals\n";
    cout << "----------------------------------------\n\n";
    print_vals ( tree );

    return 0;
}
