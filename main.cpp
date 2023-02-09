#include<iostream>
#include "src/red_black_tree.hpp"

using namespace std;

int main ()
{
     red_black_tree B(15);
        B.Insertion(10);
         B.Insertion(8);
   // red_black_tree B(11);
   // 
   // B.Insertion(14);
   // B.Insertion(15);
   // B.Insertion(7);
   // 
   // B.Insertion(1);
   // B.Insertion(5);
   // B.Insertion(8);
   // B.Insertion(4);
   // B.Insertion(50);
   // B.Insertion(40);
   // B.Insertion(60);
   // B.Insertion(19);
   // B.Insertion(21);
   // B.Insertion(14);
   // B.Insertion(15);
   // B.Insertion(13);
   // B.Insertion(17);
   // B.Insertion(45);
   // B.Insertion(35);B.Insertion(38);
   // B.Insertion(34);
  ////  B.Find(8);
   B.print();
    std::cout<<"--------------------" << std::endl;
 //   B.Delete(18);

   // std::cout<<"--------------------" << std::endl;
   // B.print();
    std::cout<<"--------------------" << std::endl;
   // B.Delete(7);
  //  B.Delete(19);
   // B.Delete(21);
   // B.Delete(4);
    std::cout<<"--------------------" << std::endl;
   // B.print();
   // B.Find(25);
   std::cout<<"----------///////----------" << std::endl;
   // B.Find(25);
   // B.print();

    std::cout<<"--------------------" << std::endl; 
    red_black_tree N;
    N.Insertion(45);
     N.Insertion(43);


    return 0;
}