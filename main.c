//
//  main.c
//  airline
//
//  Created by li on 2020/4/3.
//  Copyright © 2020年 li. All rights reserved.
//


#include "interface.h"
//#include "passager.h"
int main(int argc, const char * argv[]) {
     //insert code here...
    
   
    FlightInformation *fi = NULL;
    PassengerInformation *pi = NULL;
    InitFIHead(&fi);
    InsertFight(fi,"ca1","hk4","sh1", 2102, 2323, 2242, 1222, 1, "boei83", 31,"CCA");
    InsertFight(fi,"ca2","hk1","sh3", 651, 2122, 2232, 223, 2, "boei888", 2,"CCA");
    InsertFight(fi,"ca3","hk3","sh2", 1940, 2223, 2222, 341, 3, "boei666", 22,"CCA");
    InsertFight(fi,"ca4","hk3","sh5", 1222, 2326, 2122, 1422, 4, "boei777", 18,"CCA");
    InsertFight(fi,"ca5222","hk22","sh5", 2223, 2123, 2282, 235,5, "boei744", 12,"CCA");
    InsertFight(fi,"ca6","hk4","sh1", 2112, 2013, 2242, 321, 1, "boei83", 31,"CCA");
    InsertFight(fi,"ca11","hk1","sh3", 651, 2322, 2232, 744, 2, "boei888", 2,"CCA");
    InsertFight(fi,"ca324","hk3","sh2", 1940, 2223, 2222, 832, 3, "boei666", 22,"CCA");
    InsertFight(fi,"ca33","hk3","sh5", 1252, 2326, 2122, 9, 24, "boei777", 18,"CCA");
    InsertFight(fi,"ca41","hk22","sh5", 2213, 2123, 2282, 325,5, "boei744", 12,"CCA");
      InsertFight(fi,"ca41","hk22","sh5", 2213, 2123, 2282, 325,5, "boei744", 12,"CCA");
      InsertFight(fi,"ca41","hk22","sh5", 2213, 2123, 2282, 325,5, "boei744", 12,"CCA");
      InsertFight(fi,"ca41","hk22","sh5", 2213, 2123, 2282, 325,5, "boei744", 12,"CCA");
  
    
//    RamdonInsert(fi);
    
    InitPassHead(&pi);
    InsertPassanger(pi, 0, 0, "mike","", 10000);
   
 
    
    
    Welcome(0, fi, pi);
    
    
    
    putchar(10);
    return 0;
}
