//
//  passager.c
//  airline
//
//  Created by li on 2020/4/3.
//  Copyright © 2020年 li. All rights reserved.
//

//#include "passager.h"
#include "interface.h"
t_sint32 InitPass(PassengerInformation **pi ,t_sint32 IsBuy,t_sint32 Seat,t_int8* Name,t_int8* FightName,t_sint32 AccoutBalance)
{                                                                           //初始化乘客信息
    *pi = Malloc(PassengerInformation, 1);
    if(NULL == *pi)
    {
        ERROR_MSG("error init passinfo\n");
        return FUNC_ERR;
    }
    (*pi)->AccoutBalance = AccoutBalance;
    (*pi)->Name = Name;
    (*pi)->IsBuy = 0;
    (*pi)->Seat = 0;
    (*pi)->FightName = FightName;
    INIT_LIST_HEAD(&(*pi)->node);
    return FUNC_OK;
}
t_int8   InitPassHead(PassengerInformation **pi) //初始化头节点
{
    return InitPass(pi, 0, 0, 0, 0, 0 );
}


t_sint32 InsertPassanger(PassengerInformation *pi,t_sint32 IsBuy,t_sint32 Seat,t_int8* Name,t_int8* FightName,t_sint32 AccoutBalance)
{                                                                   //插入乘客信息
    PassengerInformation *newP =NULL;
    if(FUNC_ERR == InitPass(&newP, IsBuy, Seat, Name, FightName,AccoutBalance))
    {
        ERROR_MSG("cant init message");
        return FUNC_ERR;
    }
    list_add(&newP->node, &pi->node);
    return FUNC_OK;
}

t_sint32 ListPi(PassengerInformation *pi)
{                                                               //显示乘客信息
    PassengerInformation *pcur = NULL;
    list_for_each_entry(pcur, &pi->node, node){
        printf("%p,%d,%d,%s,%s,%d\n",pcur,pcur->IsBuy,pcur->Seat,pcur->Name,pcur->FightName,pcur->AccoutBalance);
    }
    return  FUNC_OK;
}
t_sint32 PlaneStats(FlightInformation *fi,t_int8 *name) //显示飞机座舱空余情况
{
    FlightInformation *pcur = NULL;
    // fi->FighhtName = "ca83";
    
    list_for_each_entry(pcur, (&fi->node), node)
    {
        if(strcmp(name, pcur->FighhtName) == 0)
        {
            for(t_sint32 i =0;i < 30;i++){
                
                if(pcur->Seat[i][0] == 0)
                {
                    printf("%d:@@@@@  ",i+1);
                    //    strncpy(pcur->Seat[i], "ccc", 20);
                }else
                {
                    // printf("%d:#####  ",i);
                    printf("%d:##### %s ",i+1,pcur->Seat[i]);
                }
                
            }
            printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tfightname is %s",pcur->FighhtName);
            
            putchar(10);
           
            return FUNC_OK;
           
        }
       
    }
   
   
    return FUNC_ERR;
}


t_sint32 BuyUi(FlightInformation *fi,PassengerInformation *pi , PassengerInformation *loc)
{                                                                                                       //买票UI
    //CL();
    DisplayFlightInfo(fi);
    t_int8 *input = NULL;
    t_sint32 seat = 0;
    input = Malloc(t_int8, 20);
    printf("You can input  1 to exit------>\n");
    printf("Which plane to buy? Input flight name please------>");
    scanf("%s",input);
    if(strcmp(input, "1") == 0)
    {     CL();
        PassengerUi(fi, pi);
        return FUNC_ERR ;
    }
    
   // printf("%s\n",input);
    
    if(FUNC_ERR == PlaneStats(fi, input))
    {
        CL();
        //     ============================================================================================

       printf("=====================================input error,cant find plane=============================\n");
      BuyUi(fi,pi,loc);
    }
    
    printf("which seat to buy input seat please------>");
    scanf("%d",&seat);
    if(FUNC_ERR ==  BuyTicket(fi, pi, loc->Name, input, seat))
    {     CL();
        printf("==========================Errror buy ticket check your input.===============================\n");
        printf("==========================Errror buy ticket check your input.===============================\n");
        BuyUi(fi,pi,loc);
    }
    sleep(3);
    PlaneStats(fi, input);
    BuyUi(fi,pi,loc);
    return FUNC_OK;
}

t_sint32 ChangeUi(FlightInformation *fi,PassengerInformation *pi,PassengerInformation *loc)
{                                                                                                   //换票UI
    DisplayFlightInfo(fi);
    t_int8 *input = NULL;
    t_int8 *input2 = NULL;
    t_sint32 seat = 0;
    //t_sint32 seat2 = 0;
    input = Malloc(t_int8, 20);
    input2 = Malloc(t_int8, 20);
    printf("                                                                        \n");
    if(strcmp(loc->FightName, "") != 0   )
        printf("                                    Note :the plane you have buy is %s \n====",loc->FightName);
    else{
        printf("                                    You dont have buy any tickets !\n====");
        PassengerUi(fi,pi);
    }
    printf("You can input  1 to exit------------------------------>\n");
    printf("Which plane to Change? Input flight name please------->");
    scanf("%s",input);
    if(strcmp(input, "1") == 0)
    {     CL();
        //ChangeUi(fi, pi,loc);
        PassengerUi(fi, pi);
    }
    while( strcmp(loc->FightName, input) != 0  )
    {   CL();
       // ============================================================================================

        printf("=================You have not buy this plane ticket! input right plane name!=====\n");
        printf("=================Which plane to Change? Input flight name please=================\n");
         DisplayFlightInfo(fi);
        printf("================Which plane to Change? Input flight name please------>");
        scanf("%s",input);
    }
    
  
   
    DisplayFlightInfo(fi);
     printf("==========================input flight name to change--->\n");
    scanf("%s",input2);
    if(FUNC_ERR == PlaneStats(fi, input2))
    {
        CL();
        //============================================================================================

    printf("=============================input error,cant find plane=============================\n");
        ChangeUi(fi, pi, loc);
    }
    printf("==========================input seats to change======================================\n");
      scanf("%d",&seat);
    if(FUNC_ERR ==    ChangeTicket(fi, pi, loc->Name, input, input2, seat)       )
        /////////////////BuyTicket(fi, pi, loc->Name, input, seat))
    {     CL();
        printf("==========================Errror buy ticket check your input.===============================\n");
        printf("==========================Errror buy ticket check your input.===============================\n");
      //  ChangeUi(fi,pi,loc);
    }
    PlaneStats(fi, input2);
    printf("Change Tickets success\n");
    sleep(2);
  //  ChangeUi(fi, pi,loc);
    return FUNC_OK;
}

t_sint32 RefundUi(FlightInformation *fi,PassengerInformation *pi,PassengerInformation *loc)
{                                                                                               //退票UI
    
    DisplayFlightInfo(fi);
    t_int8 *input = NULL;
    t_int8 *input2 = NULL;
    input = Malloc(t_int8, 20);
    input2 = Malloc(t_int8, 20);
    printf("                                                                        \n");
    if(strcmp(loc->FightName, "") != 0   )
        printf("========================================Note :the plane you have buy is %s \n====",loc->FightName);
    else{
        printf("=========================================== You dont have buy any tickets !\n====");
        return FUNC_ERR ;
    }
    printf("You can input  1 to exit------>\n");
    printf("Which plane to Refound? Input flight name please------>");
    scanf("%s",input);
    if(strcmp(input, "1") == 0)
    {     CL();
        //ChangeUi(fi, pi,loc);
        PassengerUi(fi, pi);
    }
    while( strcmp(loc->FightName, input) != 0  )
    {   CL();
        
        printf("=================You have not buy this plane ticket! input right plane name!================\n");
        printf("=================Which plane to Refound? Input flight name please===========================\n");
        DisplayFlightInfo(fi);
        
        printf("=======================Which plane to Refound? Input flight name please=====================\n");
        printf("=======================You can also input 10 to exit========================================\n");
        scanf("%s",input);
        if(strcmp(input, "10"))
        {
            PassengerUi(fi, pi);
        }
            
    }
    PlaneStats(fi, input);
    sleep(2);
    
    printf("=================Refounding Tickets=========================================================\n");
    RefundTickets(fi, pi, loc->Name, loc->FightName, loc->Seat);
    PlaneStats(fi, input);
   // DisplayFlightInfo(fi);
    sleep(2);
    
    printf("=================Refound success============================================================\n");
    
    
    
    return FUNC_OK;
}

// example BuyTicket(fi, pi, name, 20);
t_sint32 BuyTicket(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_sint32 input) // 买票函数
{
    FlightInformation *pcur1 = NULL;
    PassengerInformation *passpcur1 = NULL;
    // fi->FighhtName = "ca83";
    
    list_for_each_entry(pcur1, &fi->node,node)
    {
        if(strcmp(PlaneName, pcur1->FighhtName) == 0 && (input >0 && input <= 30) )
        {
            
            list_for_each_entry(passpcur1, &pi->node, node)
            {
                if(strcmp(Name, passpcur1->Name) == 0)
                {
                    //printf("%d_%s\n",input,pcur->FighhtName);
                    //printf("%s\n",passpcur->Name);
                    //  printf("%d",passpcur->AccoutBalance);
                    if ((passpcur1->AccoutBalance - pcur1->ComnPrice ) >= 0  )
                    {
                        if(strcmp(pcur1->Seat[input-1],"") != 0 )
                        {
                              printf("=============================Buy Tickets Failed ! Seat is sold out!==============================\n");
                            sleep(2);
                            return FUNC_ERR;
                        }
                        
                        if((passpcur1->IsBuy == 1) ||( strcmp(passpcur1->FightName,"") != 0))
                        {
                            
                            printf("=============================Buy Tickets Failed ! You can only buy one ticket.==================\n");
                            sleep(2);
                            return FUNC_ERR;
                        }
                        
                        
                         strncpy(pcur1->Seat[input-1],passpcur1->Name,20);
                        passpcur1->IsBuy = 1;
                        passpcur1->Seat = input-1;
                        passpcur1->AccoutBalance -=pcur1->ComnPrice;
                        passpcur1->FightName =pcur1->FighhtName;
                        pcur1->SeatLeft -= 1;
            
     printf("=============================Buy Tickets Success !==========================================\n");
                        return FUNC_OK;
                       // printf("%d_%s",input,passpcur->FightName);
                    }
                }
            }
            
        }
    }
    return FUNC_ERR;
}

t_sint32 ChangeTicket(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_int8 *newPlane,t_sint32 input)
{                                                       //换票函数
    FlightInformation *pcur = NULL;
    PassengerInformation *passpcur = NULL;
    // fi->FighhtName = "ca83";
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(strcmp(PlaneName, pcur->FighhtName) == 0)
        {
            
            list_for_each_entry(passpcur, &pi->node, node)
            {
                if(strcmp(Name, passpcur->Name) == 0)
                {
                   // pcur->Seat[passpcur->Seat][0] = 'u';
                    memset(pcur->Seat[passpcur->Seat] ,0,sizeof(pcur->Seat[passpcur->Seat]));
                    pcur->SeatLeft += 1;
                    BuyTicket(fi, pi, passpcur->Name, newPlane, input);
                    return FUNC_OK;
               //     printf("%d:%s%s \n",passpcur->Seat,pcur->Seat[18],pcur->FighhtName);
                }
            }
            
        }
    }

    return FUNC_ERR;
    
}
//退票函数
t_sint32 RefundTickets(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_sint32 input)
{
    FlightInformation *pcur = NULL;
    PassengerInformation *passpcur = NULL;
    // fi->FighhtName = "ca83";
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(strcmp(PlaneName, pcur->FighhtName) == 0)
        {
            
            list_for_each_entry(passpcur, &pi->node, node)
            {
                if(strcmp(Name, passpcur->Name) == 0)
                {
                    // pcur->Seat[passpcur->Seat][0] = 'u';
                    memset(pcur->Seat[passpcur->Seat] ,0,sizeof(pcur->Seat[passpcur->Seat]));
                 //   printf("%d:%s%s \n",passpcur->Seat,pcur->Seat[18],pcur->FighhtName);
                    passpcur->FightName = "\0";
                    passpcur->AccoutBalance += pcur->ComnPrice;
                    pcur->SeatLeft += 1;
                    
                }
            }
            
        }
    }
    
    return FUNC_OK;
}
//获取指定乘客节点地址
t_sint32 GetPassAddr(PassengerInformation *pi ,t_int8 *name ,PassengerInformation **loc)
{
    PassengerInformation *pcur = NULL;

    list_for_each_entry(pcur, &pi->node, node)
    {
        if(strcmp(name, pcur->Name)== 0)
        {
            *loc = pcur;
            return FUNC_OK;
        }
    }
    return FUNC_ERR;
}
//根据航班名查询飞机
t_sint32 SearchDpdFligtName(FlightInformation *fi, t_int8 *input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strcmp(input, pcur->FighhtName) == 0){
            count++;
            
           
            printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
            
        }
        
    }
    if(count == 0){
        
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    
    else{
        return FUNC_OK;
    }
}
//根据始发地查询飞机
t_sint32 SearchDpdFrom(FlightInformation *fi, t_int8 *input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
   // FlightInformation *loc= NULL;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->From,strlen(pcur->From)) == 0){
          //  loc = pcur;
            
            count++;
           
            printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
            
            
        }
     // return FUNC_OK;
    }
    if(count == 0){
    
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    
    else{
            return FUNC_OK;
        }
}
//根据目的地查询
t_sint32 SearchDpdTo(FlightInformation *fi, t_int8 *input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->To,strlen(pcur->To)) == 0){
            count++;
            
            printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
        }
    }
    if(count == 0){
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    else{
        return FUNC_OK;
    }
}
//根据型号查询
t_sint32 SearchDpdType(FlightInformation *fi, t_int8 *input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->AircraftTypeT,strlen(pcur->AircraftTypeT)) == 0){
            count++;
           printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
        }
    }
    if(count == 0){
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    else{
        return FUNC_OK;
    }
}
//根据到达时间查询
t_sint32 SearchDpdDepart(FlightInformation *fi, t_sint32 input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( pcur ->Depart == input){
            count++;
           
           printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
        }
    }
    if(count == 0){
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    else{
        return FUNC_OK;
    }
}
//根据到达时间查询
t_sint32 SearchDpdArrive(FlightInformation *fi, t_sint32 input)
{
    FlightInformation *pcur = NULL;
    t_sint32 count = 0;
    printf("========================================Find The Plane========================\n");
    printf("FighhtName From       To        Depart   Arrive FirstPrice ComnPrice   Otd  Type    SeatLeft\n");
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( pcur ->Arrive == input){
            count++;
           printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %02.0f  %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
        }
    }
    if(count == 0){
        INFO_MSG("cant find key\n");
        return FUNC_ERR;}
    else{
        return FUNC_OK;
    }
}

//搜索UI
t_sint32 SearchUi(FlightInformation *fi, PassengerInformation *pi )
{
    
   //   DisplayFlightInfo(fi);
    t_sint32 op =0;
    t_int8 *input = NULL;
    t_sint32 input1 = 0;
    input = Malloc(t_int8, 30);
      printf("                                                                           \n");
      printf("                                                                           \n");
    printf("==============================================================================\n");
    printf("                               Select Way To SeqPlanes.                     \n");
    printf("                               1.Search Depemdent FlightName.              \n");
    printf("                               2.Search Depemdent FROM.                     \n");
    printf("                               3.Search Depemdent TO.                     \n");
    printf("                               4.Search Depemdent Depart.                     \n");
    printf("                               5.Search Depemdent Arrive.                     \n");
    printf("                               6.Search Depemdent Type.                     \n");
    printf("                               7.exit to exit.                     \n");
    printf("==============================================================================\n");
    //    ============================================================================================
    
    printf("===================Input arrgument To Search------->");
    while( 1 == scanf("%d",&op) && (op > 0 || op <12)){
        
        // system("clear");
        switch (op) {
            case 1:printf("======================Input arrgument To Search------->");scanf(" %s",input);getchar();
                SearchDpdFligtName(fi, input);SearchUi(fi,pi);break;
            case 2:printf("======================Input arrgument To Search------->");scanf(" %s",input);getchar();SearchDpdFrom(fi, input);SearchUi(fi,pi);break;
            case 3:printf("======================Input arrgument To Search------->");scanf(" %s",input);getchar();SearchDpdTo(fi, input);SearchUi(fi,pi);break;
            case 4:printf("======================Input arrgument To Search------->");scanf(" %d",&input1);getchar();SearchDpdDepart(fi,input1);SearchUi(fi,pi);break;
            case 5:printf("======================Input arrgument To Search------->");scanf(" %d",&input1);getchar();SearchDpdArrive(fi,input1);SearchUi(fi,pi);break;
            case 6:printf("======================Input arrgument To Search------->");scanf(" %s",input);getchar();SearchDpdType(fi, input);SearchUi(fi,pi);break;
            case 7:PassengerUi(fi, pi);break;
            default:SearchUi(fi,pi );
                break;
        }
    }
    getchar();
    SeqUi(fi,pi);
    return FUNC_OK;
}
