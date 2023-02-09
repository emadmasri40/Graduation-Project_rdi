
#include <iostream>
#include "red_black_tree.hpp"
#include <stdio.h>
const char* Color_Name[2] = {"Black","Red"}; 

red_black_tree::red_black_tree()
{
    Root = nullptr;
   
};
red_black_tree::red_black_tree(int val)
{
    Root = new Node();
    Root->key= val;
    Root->Color= Black;
    Root->Parent=nullptr;
    Root->Left = new Node()  ;
    Root->Left->Parent= Root;
    Root->Right =new Node();
    Root->Right->Parent=Root;
};
void red_black_tree::Find(int val)
{
    Nodeptr Y = this->Root;
    Nodeptr P = search(Y,val);

    if(P != nullptr)
    {
        std::cout<< " value " << P->key << " color " << Color_Name[P->Color]<< std::endl;
    }
    else
    std::cout<< " the value not fond ";

}
Nodeptr red_black_tree::search(Nodeptr root ,int val)
{
    if( ((root->Left == nullptr )&&(root->Right==nullptr)))
    {

        return nullptr ;
    }
    else if (root->key == val)
    {
        return root ;
    }
     else if (root->key < val)
    {
        return search(root->Right , val);

    }
   
        

    return search(root->Left , val);;
};
void red_black_tree::Insertion(int val)
{
    
    
     if( Root == nullptr)
     {
         Root = new Node();
         Root->key=val;
         Root->Color=Black;
         Root->Parent=nullptr;
         Root->Left = new Node()  ;
         Root->Left->Parent= Root;
         Root->Right =new Node();
         Root->Right->Parent=Root;

        return ;

     }
    Nodeptr Y= this->Root;
     while (Y->Left !=nullptr || Y->Right !=nullptr )
     {
        if (Y->key < val)
            Y = Y->Right;
        else
            Y=Y->Left;
     }
     Y->key = val;
     Y->Color=Red;
     Y->Left =new Node();
     Y->Left->Parent=Y;
     Y->Right = new Node() ;
     Y->Right->Parent=Y;
    if (Y->Parent->Color != Y->Color)
    {
     std::cout<<"the value  "<<val; 
    std::cout<< "  the Parent   " <<Y->Parent->key << std::endl;
    }
    else 
    {
        Nodeptr Grant_father = Y->Parent->Parent;
        if (Grant_father->Left->Color && Grant_father->Right->Color) // case1 recolor parent and uncle and Grand parent =uncle = read
        {
            recolor(Y);
        }
        else    // parent = red and uncle != red 
        {
            if( (Y->key < Y->Parent->key ) && (Y->Parent->key < Grant_father->key)) // L->L
            {
                     recolor(Y->Parent);
                    rotate_right(Y->Parent);
                    
                    
            }
             else if( (Y->key > Y->Parent->key ) && (Y->Parent->key > Grant_father->key))  
             {
                 rotate_left(Y->Parent);
                  printf("R->R");
             }

        }
       

    }
    Root->Color=Black;
 
};

void red_black_tree::print_p(Nodeptr root)
{

    if (root->Left == nullptr && root->Right==nullptr)
    { 
        printf("\n");
        return ;
    }
       
    if (root->Right !=nullptr)
        {
            printf(" %d color %s -->R  ",root->key , Color_Name[root->Color]);
            print_p(root->Right) ;
           
        }
    if (root->Left !=nullptr)
        {
             printf("  %d color %s --->L  ",root->key , Color_Name[root->Color]);
             print_p(root->Left) ;
            // printf("\n");
        }  
    
};
void red_black_tree::print()
{
    Nodeptr Y=this->Root;
    print_p(Y);
};


void red_black_tree::Delete(int val)
{

    Nodeptr Re_S = search(this->Root , val);
    if(Re_S == nullptr)
    {
        return ;
    }
    Nodeptr Re_Slr = Re_S->Left->Right ;
    Nodeptr Re_Sll = Re_S->Left->Left ;
    Nodeptr Re_Srl = Re_S->Right->Left ;
    Nodeptr Re_Srr = Re_S->Right->Right ;
    if(!Re_S->Left->Right && !Re_S->Left->Left  && !Re_S->Right->Left  && !Re_S->Right->Right ) // this case delete leaf node
    {
        //delete Re_S;
       //   Re_S->key = 0;
        //delete (Re_Sll , Re_Slr , Re_Srl , Re_Srr) ;// Re_S->Right  ;// Re_Slr , Re_Srr , Re_Srl ;
        Re_S->Left=nullptr;
        Re_S->Right=nullptr;
        return ;
    }
    else
    {
     
        if ((Re_S->Left->key) > (Re_S->Right->key)) // this case delete left > right and right leaf node
        {
            Re_S->Parent->Left = Re_S->Left; 
            Re_S->Left->Parent = Re_S->Parent;
            delete Re_S;
            return ;
        }
        else
        {
            Nodeptr Re_max_right_left = new Node(); // 

            Re_max_right_left = Re_S->Right; //store leaf of left to right branch 
            if(Re_S != this->Root)
            {

              Re_S->Parent->Right = Re_S->Right; //

              Re_S->Right->Parent=Re_S->Parent;  //
            }
            else  // in case delete root 
            {
                this->Root = Re_S->Right;
                Root->Color=Black;

            }

            while (Re_max_right_left->Left->Left!=nullptr)
                {
                     Re_max_right_left = Re_max_right_left->Left;
                }

            Re_max_right_left->Left  = Re_S->Left;
            Re_S->Left->Parent = Re_max_right_left;
             delete Re_S ;
             return ;

        }
    }
};

void red_black_tree::recolor(Nodeptr root)
{

         root->Parent->Color = ((root->Parent->Color) == Black) ? Red : Black ;
         root->Parent->Left->Color = ((root->Parent->Left->Color) == Black) ? Red : Black ;
         root->Parent->Right->Color = ((root->Parent->Right->Color) == Black) ? Red : Black ;
/*
   //  Nodeptr Grant_father =nullptr;
      //      if(root == Root)
                 Grant_father = root->Parent;
            else
                  Grant_father = root->Parent->Parent;
            Grant_father->Left->Color=Black; // recolor parent
            Grant_father->Right->Color=Black; // recolor uncle
            Grant_father->Color =  // toggle the pearnt */
       
}


void red_black_tree::rotate_left(Nodeptr root)
{
    Nodeptr parent = root->Parent ;

     parent->Right=root->Left;
     root->Left = parent ; 
    if(parent==Root)
    {
         root->Parent =nullptr;
         Root =  root;
         return ;
    }
         Nodeptr Grand_root = parent->Parent; // set Grand_parent
        if(Grand_root->key < root->key )
                 Grand_root->Right=root;
        else
             Grand_root->Left=root;
}
void red_black_tree::rotate_right(Nodeptr root)
{
    
    Nodeptr parent = root->Parent ;

         parent->Left=root->Right;
         root->Right = parent;
    if(parent==Root)
    {

         
         root->Parent =nullptr;
         Root =  root;
         return ;
    }
   

         Nodeptr Grand_root = parent->Parent; // set Grand_parent
        if(Grand_root->key < root->key )
                 Grand_root->Right=root;
        else
             Grand_root->Left=root;
   
          
};