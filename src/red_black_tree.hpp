#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

enum Color_set {Black,Red} ;

struct Node   
{
    Color_set Color; 
    int key;
    Node *Right =nullptr  ;
    Node *Left = nullptr ;
    Node *Parent = nullptr ;
    
};
typedef Node* Nodeptr;

class red_black_tree
{
private:

Nodeptr Root;
//Nodeptr NIL;
Nodeptr search (Nodeptr,int);
void print_p(Nodeptr);
void resolt();
void recolor(Nodeptr);
void rotate_left(Nodeptr) ;
void rotate_right(Nodeptr) ;
public:
    red_black_tree();
    red_black_tree(int);
    void Find (int);
    void print ();
    void Insertion (int);
    void Delete(int) ;
    
   // ~red_black_tree();
};




#endif
