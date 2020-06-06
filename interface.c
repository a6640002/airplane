//
//  interface.c
//  airline
//
//  Created by li on 2020/4/3.
//  Copyright © 2020年 li. All rights reserved.
//

#include "interface.h"
//#include "passager.h"
t_sint32 InitFI (FlightInformation **fi,t_int8 *FighhtName,t_int8 *From,t_int8 *To,t_sint32 Depart,t_sint32 Arrive,t_sint32 FirstPrice,t_sint32 ComnPrice,t_float32 Correctness,t_int8 *AircraftTypeT,t_sint32 SeatLeft,t_int8      *AirLine
)
{
    *fi = Malloc(FlightInformation, sizeof(FlightInformation));  //初始化普通节点
    if(NULL == *fi )
    {
        ERROR_MSG("cant init fight");
        return  FUNC_OK;
    }
    
    (*fi)->AircraftTypeT = AircraftTypeT ;
    (*fi)->Arrive        = Arrive;
    (*fi)->ComnPrice     = ComnPrice;
    (*fi)->Correctness   = Correctness;
    (*fi)->Depart        = Depart;
    (*fi)->FighhtName    = FighhtName ;
   // strcpy((*fi)->FighhtName, FighhtName);
    (*fi)->FirstPrice    = FirstPrice;
    (*fi)->From          = From ;
    (*fi)->SeatLeft      = SeatLeft;
     (*fi)->To           = To;
    (*fi)->AirLine       = AirLine;
   // for(t_int8 i = 0;i<30; i++)
    //(*fi)->Seat[i][0] ='u';
   memset((*fi)->Seat, 0, sizeof((*fi)->Seat)*30);
    //(*fi)->Seat = NULL;
   // memset((*fi)->FighhtNam, 0, sizeof((*fi)->FighhtNam));
   // (*fi)->FighhtNam = "";
    INIT_LIST_HEAD(& ((*fi)->node));
    return FUNC_OK;
}


t_sint32 InitFIHead (FlightInformation **fi)                                                // 初始化头节点
{
    
    return InitFI(fi, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0) ? FUNC_OK : FUNC_ERR;
}

t_sint32 InsertFight(FlightInformation *fi,t_int8 *FighhtName,t_int8 *From,t_int8      *To,t_sint32 Depart,t_sint32 Arrive,t_sint32 FirstPrice,t_sint32 ComnPrice,t_float32 Correctness,t_int8 *AircraftTypeT,t_sint32 SeatLeft,t_int8 *AirLine)
{
    FlightInformation *new1 = NULL;
    if (FUNC_ERR== InitFI(&new1, FighhtName, From, To, Depart,Arrive,FirstPrice,ComnPrice,Correctness,AircraftTypeT,SeatLeft,AirLine)){
        ERROR_MSG("cant init fight");
        return FUNC_ERR;
        
    }
    list_add( &new1->node , &fi->node);
    
    return  FUNC_OK;
}


void CL(void)
{
    printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n"); printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
     printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}
t_sint32 ListFlight(FlightInformation *fi)              //遍历显示所有飞机
{
    FlightInformation *pcur = NULL;
    list_for_each_entry(pcur, &fi->node, node){
        printf("%-10s %-6s %-6s %02d:%02d   %02d:%02d   %-4d       %-4d      %02.0f  %-10s  %02d        %-10s\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft,pcur->AirLine);
        
        //  printf("%d \n",sizeof(*pcur));
    }
    return  FUNC_OK;
}

void     DisplayFlightInfo(FlightInformation *fi)          //显示所有飞机 带格式
{
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    while(PlaneAutoDelete(fi) != FUNC_ERR);
    (void)BoardingAttention(fi);
    
    BoardingAttention(fi);
    printf("============================================================================================\n");
    printf("                                FlightInformation                                          \n");
    printf("                                                                                         \n");
    printf("                                                                                           \n");
    printf("FighhtName From   To     Depart  Arrive FirstPrice ComnPrice  Otd Type      SeatLeft  AriLine   \n");
    ListFlight(fi);
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("                                                                        time: %02d:%02d             \n",p->tm_hour+8,p->tm_min);
    printf("============================================================================================\n");
   
    
}
void DisplaySinglePlane(FlightInformation *pcur)                        //显示某节点航班参数
{
    printf("FighhtName From       To         Depart Arrive FirstPrice ComnPrice Otd   Type  SeatLeft   \n");
    printf("%-10s %-10s %-10s %02d:%02d   %02d:%02d   %-4d     %-4d     %-4.2f %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
    
}
void     Welcome(t_sint32 input,FlightInformation *fi,PassengerInformation *pi)   // 欢迎界面。入口函数
{
   // CL();
    DisplayFlightInfo(fi);
    printf("============================================================================================\n");
    printf("                                                                                            \n");
    printf("                                                                                             \n");
    printf("                                                                                             \n");
    printf("                       Wlecome  input numbers to opera .                                      \n");
    printf("                                 1> for admin .                                               \n");
    printf("                                 2> for Passanger .                                           \n");
    printf("                                 3> for exit.                                                \n");
    printf("                                                                                            \n");
    printf("                                                                                             \n");
    printf("                                                                                              \n");
    printf("============================================================================================\n");
   

    t_sint32 op =0;
    scanf(" %d",&op);
    getchar();
    
    
     
   
    switch (op) {
        case 1:
            if(FUNC_OK == Login(fi,pi))
               {admin(fi,pi);}
            break;
        case 2:
            
            if(FUNC_OK == LoginPass(fi,pi))
            {PassengerUi(fi,pi);}
            ;
            break;
        case 3:
          
            exit(0);
            break;
       
        default:  Welcome(0,fi,pi);
            break;
    
    }
}


t_sint32 GetFlightAddr(FlightInformation *fi,t_int8 *input,FlightInformation **loc) // 获取航班信息节点地址
{
    FlightInformation *pcur = NULL;
   
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->FighhtName,sizeof(*pcur->FighhtName)) == 0){
            *loc = pcur;
            
          //  printf("%s  ",(*loc)->FighhtName );
            return FUNC_OK;
            
        }
        
    }
   // INFO_MSG("cant find ");
    return FUNC_ERR;
}


t_sint32 SearchDpdKey(FlightInformation *fi, t_int8 *input)          //根据关键字获取节点信息并且打印
{
    FlightInformation *pcur = NULL;
    FlightInformation *loc= NULL;
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strcmp(input, pcur->FighhtName) == 0){
            loc = pcur;
            
            printf("========================================Find The Plane======================================\n");
            printf("FighhtName From      To          Depart Arrive FirstPrice ComnPrice Otd    Type     SeatLeft\n");
            printf("%-10s %-10s %-10s %-2d:%2d   %-2d:%2d   %-4d       %-4d       %-4.2f %-10s%-2d\n",pcur->FighhtName, pcur->From, pcur->To, pcur->Depart/100,pcur->Depart%100,pcur->Arrive/100,pcur->Arrive%100,pcur->FirstPrice,pcur->ComnPrice,pcur->Correctness,pcur->AircraftTypeT,pcur->SeatLeft);
          return FUNC_OK;
            
        }
        
    }
    INFO_MSG("cant find key");
    return FUNC_ERR;
}

t_sint32 DeleteDpdName(FlightInformation *head, t_int8 *input) //按名字删除航班
{
    FlightInformation *pcur = NULL;

    list_for_each_entry(pcur, &head->node, node)
    {
        if( strcmp(input, pcur->FighhtName) == 0){
            list_del(&pcur->node);
            free(pcur);
            return FUNC_OK;
    }
}

return FUNC_ERR;
}


t_sint32 DeleteDpdFrom(FlightInformation *head, t_int8 *input) //按起飞地删除航班
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &head->node, node)
    {
        if( strcmp(input, pcur->From) == 0){
            list_del(&pcur->node);
            free(pcur);
            return FUNC_OK;
        }
    }
    
    return FUNC_ERR;
}
t_sint32 DeleteDpdTo(FlightInformation *head, t_int8 *input) // 按目的地删除航班
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &head->node, node)
    {
        if( strcmp(input, pcur->To) == 0){
            list_del(&pcur->node);
            free(pcur);
            return FUNC_OK;
        }
    }
    
    return FUNC_ERR;
}
t_sint32 BoardingAttention(FlightInformation *fi) // 登机提醒
{
    
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
       // if(((pcur ->Depart)/100*60+pcur ->Depart%100 ) > ((p->tm_hour+8)*60+p->tm_min)+30 ){
        if(((pcur ->Depart)/100*60+pcur ->Depart%100 ) < ((p->tm_hour+8)*60+p->tm_min)+30 ){ //判断是否快到了 时间按分钟算
            printf(" Announce %s is boading in 30 min\n",pcur->FighhtName);
            return FUNC_OK;
        }
    }
    return FUNC_ERR;
}

t_sint32 PlaneAutoDelete(FlightInformation *fi) // 自动删除飞机
{
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( pcur->Depart < ((p->tm_hour+8)*100+p->tm_min)   ){
           list_del( &pcur->node  );
            printf("Attemtion  plane[%s] time is out  delete...\n",pcur->FighhtName);
            
            //sleep(3);
            return FUNC_OK;
        }
    }
    //printf("%d\n",p->tm_hour+8);
   // INFO_MSG("No plane need to delete\n");
    return FUNC_ERR;
}

void admin(FlightInformation *fi,PassengerInformation *pi)        //管理员界面
{
    CL();
    t_sint32 input = 0;
    DisplayFlightInfo(fi);
    
    printf("                       Wlecome  input numbers to opera .                                      \n");
    printf("                                 1> for DelFlight .                                          \n");
    printf("                                 2> for ModifyFlight .                                         \n");
    printf("                                 3> for exit.                                                \n");
    scanf("%d",&input);
    if(3 == input)
    {
        
        Welcome(0, fi, pi) ;
    }
    if(2 == input)
    {
         ModifyFlight(fi,pi) ;
    }
   
    if(1 == input)
    {
        DeleteFlightDpdItem(fi,pi);
    }
    
}
void DeleteFlight(FlightInformation *fi,PassengerInformation *pi) // 删除航班ui
{
    t_int8 *input = NULL;
    input = Malloc(t_int8, 30);
    DisplayFlightInfo(fi);
    
    printf("                             Select Flight To Del.                     \n");
    printf("                           you can alse input 1 to exit                 \n");
    
    while (( 1!= scanf(" %s",input)));
  
       
    getchar();
    
    if(strcmp(input,"1") == 0)
    {
        (void)PassengerUi(fi, pi);
        return;
        
    }
    
    
    if(FUNC_ERR ==  DeleteDpdName(fi, input))
    {
        printf("                           \"%s\" is not in database,make sure input. \n",input);
        sleep(3);
        DeleteFlight(fi,pi);
        return;
        //admin(fi);
    }else{
        printf("                              Del...%s........                      \n",input);
        sleep(3);
        printf("                              Del Done!                             \n");
        sleep(3);
        printf("                                input numbers to opera .                                      \n");
        printf("                                 1> for DelFlight .                                          \n");
        printf("                                 2> for ModifyFlight .                                         \n");
        printf("                                 3> for exit.                                                \n");
        DeleteFlight(fi,pi);
        return;
        //admin(fi);
    }
}

void ModifyFlight(FlightInformation *fi,PassengerInformation *pi) //修改飞机信息UI
{  DisplayFlightInfo(fi);
    printf("                             Select FlightName To Modify.                     \n");
    t_int8 *input = NULL;
    t_sint32 op =0;
    t_sint32 input1 = 0;
    t_float32 input2 = 0.1;
    FlightInformation *loc = NULL;
    input = Malloc(t_int8, 30);
    scanf(" %s",input);
    getchar();
    if(FUNC_ERR == GetFlightAddr(fi, input, &loc))
    {
        
        CL();
        printf("==========================================cant find plane=================================== \n");
         printf("==========================================input 1 to admin menu============================ \n");
        if(strcmp(input, "1") == 0 ){
            admin(fi,pi);}
        ModifyFlight(fi,pi);
    }
   CL();
     DisplaySinglePlane(loc);
    printf("                               Select Way To Modify.                     \n");
    printf("                               1.Modify Depemdent FlightName.              \n");
    printf("                               2.Modify Depemdent FROM.                     \n");
    printf("                               3.Modify Depemdent TO.                     \n");
    printf("                               4.Modify Depemdent Depart.                     \n");
    printf("                               5.Modify Depemdent Arrive.                     \n");
    printf("                               6.Modify Depemdent FirstPrice.                     \n");
    printf("                               7.Modify Depemdent ComnPrice.                     \n");
    printf("                               8.Modify Depemdent Otd.                     \n");
    printf("                               9.Modify Depemdent Type.                     \n");
    printf("                               10.Modify Depemdent SeatLeft.                     \n");
    printf("                               11.exit to admin memu.                     \n");
   
    printf("-->>");
    scanf(" %d",&op);
    getchar();
    //      ============================================================================================

    printf("=============================input arrgument?>>>>>>>>>>>>>>>>>>>");
   // system("clear");
    switch (op) {
        case 1: if( 1 != scanf("%s",input)){ModifyFlight(fi,pi);}loc->FighhtName = input;ModifyFlight(fi,pi);break;
        case 2:scanf("%s",input);loc->From = input;ModifyFlight(fi,pi);break;
        case 3:scanf("%s",input);loc->To = input;ModifyFlight(fi,pi);break;
        case 4:if( 1 != scanf("%d",&input1)){ModifyFlight(fi,pi);}loc->Depart = input1;ModifyFlight(fi,pi);break;
        case 5:if( 1 != scanf("%d",&input1)){ModifyFlight(fi,pi);}loc->Arrive = input1;ModifyFlight(fi,pi);break;
        case 6:if( 1 != scanf("%d",&input1)){ModifyFlight(fi,pi);}loc->FirstPrice = input1;ModifyFlight(fi,pi);break;
        case 7:if( 1 != scanf("%d",&input1)){ModifyFlight(fi,pi);}loc->ComnPrice = input1;ModifyFlight(fi,pi);break;
        case 8:if( 1 != scanf("%f",&input2)){ModifyFlight(fi,pi);}loc->Correctness = input2;ModifyFlight(fi,pi);break;
        case 9:scanf("%s",input);loc->AircraftTypeT = input;ModifyFlight(fi,pi);break;
        case 10:if( 1 != scanf("%d",&input1)){ModifyFlight(fi,pi);}loc->SeatLeft = input1;ModifyFlight(fi,pi);break;
        case 11:admin(fi,pi);break;
            //         ============================================================================================

        default:printf("===============================================error input==================================\n");
            break;
    }
    DisplaySinglePlane(loc);
    
   // DisplayFlightInfo(fi);
    
    
}


void DeleteFlightDpdItem(FlightInformation *fi,PassengerInformation *pi)       //根据关键字删除飞机信息ui
{
    DisplayFlightInfo(fi);
    
    t_int8 *input = NULL;
    t_sint32 op =0;
    t_sint32 input1 = 0;
    t_float32 input2 = 0.1;
    //FlightInformation *loc = NULL;
    input = Malloc(t_int8, 30);
    
    CL();
   DisplayFlightInfo(fi);
    printf("                               Select Way To Modify.                     \n");
    printf("                               1.Delete Depemdent FlightName.              \n");
    printf("                               2.Delete Depemdent FROM.                     \n");
    printf("                               3.Delete Depemdent TO.                     \n");
    printf("                               4.Delete Depemdent Depart.                     \n");
    printf("                               5.Delete Depemdent Arrive.                     \n");
    printf("                               6.Delete Depemdent FirstPrice.                     \n");
    printf("                               7.Delete Depemdent ComnPrice.                     \n");
    printf("                               8.Delete Depemdent Otd.                     \n");
    printf("                               9.Delete Depemdent Type.                     \n");
    printf("                               10.Delete Depemdent SeatLeft.                     \n");
    printf("                               11.exit to admin memu.                     \n");
    scanf(" %d",&op);
    
    getchar();
    
    
    if(op == 11)
    {
        admin(fi,pi);
        return;
    }
          //============================================================================================

    printf("============================InputArgument To Dele----------->");
    
    switch (op) {
        case 1:scanf(" %s",input);getchar(); while(FUNC_ERR !=   DelFlightdDpdPlaneName(fi,input)    )   {}  ;break;
        case 2:scanf(" %s",input);getchar();   while(FUNC_ERR !=  DeleteDpdFrom(fi, input)         )      {} ;break;
        case 3:scanf(" %s",input);getchar();   while(FUNC_ERR !=  DeleteDpdTo(fi, input)           )    {}  ;break;
        case 4:scanf(" %d",&input1);getchar(); while(FUNC_ERR !=  DelFlightdDpdDepart(fi, input1)   )    {} ;break;
        case 5:scanf(" %d",&input1);getchar(); while(FUNC_ERR !=  DelFlightdDpdArrive(fi, input1)    )   {} ;break;
        case 6:scanf(" %d",&input1);getchar(); while(FUNC_ERR !=  DelFlightdDpdFirstPrice(fi, input1) )  {} ;break;
        case 7:scanf(" %d",&input1);getchar();  while(FUNC_ERR != DelFlightdDpdComnPrice(fi, input1) )   {} ;break;
        case 8:scanf(" %f",&input2);getchar(); while(FUNC_ERR !=  DelFlightdDpdOtd(fi, input2)     )     {} ;break;
        case 9:scanf(" %s",input);getchar() ;  while(FUNC_ERR !=  DelFlightdDpdType(fi, input)    )      {} ;break;
        case 10:scanf(" %d",&input1);getchar() ;while(FUNC_ERR != DelFlightdDpdSeatLeft(fi, input1) )   {};break;
        case 11:admin(fi,pi);break;
        default:printf("-----------------error input-----------------");
            break;
    }

    
    DisplayFlightInfo(fi);
    DeleteFlightDpdItem(fi,pi);
    
    
}

t_sint32 DelFlightdDpdPlaneName(FlightInformation *fi,t_int8 *input)       //g根据名字删除航班
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strcmp(input, pcur->FighhtName) == 0){
            list_del(&pcur->node);
            free(pcur);
            return FUNC_OK;
            
            //  printf("%s  ",(*loc)->FighhtName );
            
            
        }
       //
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdFrom(FlightInformation *fi,t_int8 *input)       //根据始发地删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->From,strlen(pcur->From)) == 0){
            list_del(&pcur->node);
            free(pcur);
              return FUNC_OK;
            //  printf("%s  ",(*loc)->FighhtName );
            
            
        }
      
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdTo(FlightInformation *fi,t_int8 *input) //根据目的地删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->To,strlen(pcur->To)) == 0){
            list_del(&pcur->node);
            free(pcur);
            return FUNC_OK;
            //  printf("%s  ",(*loc)->FighhtName );
            
            
        }
        
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdDepart(FlightInformation *fi,t_sint32 input)   //根据起飞时间删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->Depart == input){
            list_del(&pcur->node);
            free(pcur);
            //  printf("%s  ",(*loc)->FighhtName );
             return FUNC_OK;
            
        }
       
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdArrive(FlightInformation *fi,t_sint32 input) //根据到达时间删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->Arrive == input){
            list_del(&pcur->node);
            free(pcur);
            //  printf("%s  ",(*loc)->FighhtName );
            
            return FUNC_OK;
        }
        
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdFirstPrice(FlightInformation *fi,t_sint32 input) //根据头等舱价格删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->FirstPrice == input   ){
            list_del(&pcur->node);
            free(pcur);
            //  printf("%s  ",(*loc)->FighhtName );
          
             return FUNC_OK;
        }
        
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdComnPrice(FlightInformation *fi,t_sint32 input) // 根据普通价格删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->ComnPrice == input  ){
            list_del(&pcur->node);
            
            //  printf("%s  ",(*loc)->FighhtName );
            free(pcur);
             return FUNC_OK;
        }
       
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdOtd (FlightInformation *fi,t_float32 input)      //根据准点率删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->Correctness == input  ){
            list_del(&pcur->node);
            free(pcur);
            //  printf("%s  ",(*loc)->FighhtName );
            return FUNC_OK;
            
        }
        
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdType(FlightInformation *fi,t_int8 *input)       //根据飞机型号删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if( strncmp(input, pcur->AircraftTypeT,strlen(pcur->AircraftTypeT) )== 0){
         //  printf("%s \n  ",pcur->FighhtName );
           // printf("%d \n  ",sizeof(*input) );
           // printf("%d \n  ",strlen(pcur->AircraftTypeT) );
            free(pcur);
            list_del(&pcur->node);
            
            
          return FUNC_OK;
            
        }
        
        
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

t_sint32 DelFlightdDpdSeatLeft(FlightInformation *fi,t_sint32 input)          //根据座位剩余数删除
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        if(  pcur->SeatLeft == input                        ){
            list_del(&pcur->node);
            free(pcur);
            //  printf("%s  ",(*loc)->FighhtName );
             return FUNC_OK;
         
        }
      
    }
    // INFO_MSG("cant find ");
    return FUNC_ERR;
}

void PrintM(t_int8 * input )  //待开发
{
    printf("                   =========================================                \n ");
    printf("                                                                            \n ");
    printf("                                                                            \n ");
    printf("                     %s                                                   \n",input);
//    printf("                    \033[47;31mThis is a color test.\033[0m \n");
    printf("                                                                            \n");
    printf("                                                                            \n");
    printf("                   =========================================                \n");
    
}

t_sint32 FlightSeqDpdFlightName(FlightInformation *fi)  //根据航班名字排序
{
    
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
      FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
            if ( strcmp(pcur->FighhtName, next->FighhtName) < 0 )
            {
                t_int8 *tmp = NULL;
                t_sint32 tmp1 = 0;
                t_float32 tmp2 = 0.1;
                FlightInformation *tmp3 = NULL;
                InitFIHead(&tmp3);
                tmp =pcur->FighhtName;
                pcur->FighhtName =next->FighhtName;
                next->FighhtName = tmp;
                
                tmp =pcur->From;
                pcur->From =next->From;
                next->From = tmp;
                
                tmp =pcur->To;
                pcur->To =next->To;
                next->To = tmp;
                
                tmp =pcur->AircraftTypeT ;
                pcur->AircraftTypeT =next->AircraftTypeT;
                next->AircraftTypeT = tmp;
                
                tmp1 =pcur->Arrive;
                pcur->Arrive =next->Arrive;
                next->Arrive = tmp1;
                
                tmp1 =pcur->Depart ;
                pcur->Depart =next->Depart;
                next->Depart = tmp1;
                
                tmp1 =pcur->ComnPrice ;
                pcur->ComnPrice =next->ComnPrice;
                next->ComnPrice = tmp1;
                
                tmp1 =pcur->FirstPrice ;
                pcur->FirstPrice =next->FirstPrice;
                next->FirstPrice = tmp1;
                
                tmp1 =pcur->SeatLeft ;
                pcur->SeatLeft =next->SeatLeft;
                next->SeatLeft = tmp1;
                
                tmp2 =pcur->Correctness ;
                pcur->Correctness =next->Correctness;
                next->Correctness = tmp2;
                memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
                memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
                memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));

            }
        }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdType(FlightInformation *fi)         //根据航班飞机型号排序
{
    
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( strcmp(pcur->AircraftTypeT, next->AircraftTypeT) < 0 )
        {
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}
t_sint32 FlightSeqDpdFrom(FlightInformation *fi)       //根据航班始发地排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( strcmp(pcur->From, next->From) < 0 )
        {
          
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdTo(FlightInformation *fi)  //根据航班目的地排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( strcmp(pcur->To, next->To) < 0 )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdDepart(FlightInformation *fi) //根据航班起飞时间排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->Depart < next->Depart )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdArrive(FlightInformation *fi)    //根据航班到达飞时间排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->Arrive < next->Arrive )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdComnPrice(FlightInformation *fi) //根据航班普通价格排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->ComnPrice < next->ComnPrice )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdFirstPrice(FlightInformation *fi)     //根据航班头等舱价格排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->FirstPrice < next->FirstPrice )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdSeatLeft(FlightInformation *fi)        //根据航班座位y剩余数格排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->SeatLeft < next->SeatLeft )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 FlightSeqDpdOtd(FlightInformation *fi)         //根据航班准点率排序
{
    FlightInformation *pcur = NULL;
    
    list_for_each_entry(pcur, &fi->node, node)
    {
        
        FlightInformation *next = container_of(pcur->node.next, FlightInformation, node);
        
        list_for_each_entry(next, &fi->node, node)
        if ( pcur->Correctness < next->Correctness )
        {
            
            t_int8 *tmp = NULL;
            t_sint32 tmp1 = 0;
            t_float32 tmp2 = 0.1;
            FlightInformation *tmp3 = NULL;
            InitFIHead(&tmp3);
            tmp =pcur->FighhtName;
            pcur->FighhtName =next->FighhtName;
            next->FighhtName = tmp;
            
            tmp =pcur->From;
            pcur->From =next->From;
            next->From = tmp;
            
            tmp =pcur->To;
            pcur->To =next->To;
            next->To = tmp;
            
            tmp =pcur->AircraftTypeT ;
            pcur->AircraftTypeT =next->AircraftTypeT;
            next->AircraftTypeT = tmp;
            
            tmp1 =pcur->Arrive;
            pcur->Arrive =next->Arrive;
            next->Arrive = tmp1;
            
            tmp1 =pcur->Depart ;
            pcur->Depart =next->Depart;
            next->Depart = tmp1;
            
            tmp1 =pcur->ComnPrice ;
            pcur->ComnPrice =next->ComnPrice;
            next->ComnPrice = tmp1;
            
            tmp1 =pcur->FirstPrice ;
            pcur->FirstPrice =next->FirstPrice;
            next->FirstPrice = tmp1;
            
            tmp1 =pcur->SeatLeft ;
            pcur->SeatLeft =next->SeatLeft;
            next->SeatLeft = tmp1;
            
            tmp2 =pcur->Correctness ;
            pcur->Correctness =next->Correctness;
            next->Correctness = tmp2;
            memcpy( tmp3->Seat, pcur->Seat,sizeof(pcur->Seat));
            memcpy( pcur->Seat, next->Seat,sizeof(pcur->Seat));
            memcpy( next->Seat, tmp3->Seat,sizeof(pcur->Seat));
            
        }
    }
    return FUNC_OK;
}

t_sint32 PassengerUi(FlightInformation *fi,PassengerInformation *pi) //乘客UI
{
    
    
    
    
    t_sint32 input = 0;
    PassengerInformation *loc = NULL;
    if(FUNC_ERR ==  GetPassAddr(pi, "mike", &loc))
    {
        printf("get passaddr error \n");
    }
    
    while(-1 != input)
    {
        //Welcome(input,fi,pi);
        printf("============================================================================================\n");
        printf("                                                                                        \n");
        printf("                                                                                        \n");
        printf("                                                                                        \n");
        printf("                Welcome  %s ! input numbers to opera .                                   \n", loc->Name);
        printf("                         1>  ListFlight Dpd Key.                                        \n");
        printf("                         2>  BUY  Flight Ticket .                                     \n");
        printf("                         3>  Air Tickets Changing.                                    \n");
        printf("                         4>  Refund  Flight Ticket                                      \n");
        printf("                         5>  Search  Flight  Dpd Keys.                                     \n");
        
        printf("                         6>  Return  to login .                                     \n");
        printf("                                                                                        \n");
        printf("                                                                                        \n");
        printf("                                                                                         \n");
        printf("============================================================================================\n");
        scanf(" %d",&input);
        getchar();
        switch (input) {
                
            case 2 :BuyUi(fi,pi,loc); break;
            case 3 :ChangeUi(fi,pi,loc); break;
            case 4 :RefundUi(fi,pi,loc); break;
            case 1 :SeqUi(fi,pi);break;
            case 5 :SearchUi(fi,pi);break;
            case 6 :Welcome(0,fi,pi); break;
                
            default:printf("input error"); break;
        }
        
    }
    return FUNC_OK;
}

t_sint32 SeqUi(FlightInformation *fi, PassengerInformation *pi )     // 排序UI
{
  //  DisplayFlightInfo(fi);
    t_sint32 op =0;
    printf("                               Select Way To SeqPlanes.                     \n");
    printf("                               1.SeqPlanes Depemdent FlightName.              \n");
    printf("                               2.SeqPlanes Depemdent FROM.                     \n");
    printf("                               3.SeqPlanes Depemdent TO.                     \n");
    printf("                               4.SeqPlanes Depemdent Depart.                     \n");
    printf("                               5.SeqPlanes Depemdent Arrive.                     \n");
    printf("                               6.SeqPlanes Depemdent FirstPrice.                     \n");
    printf("                               7.SeqPlanes Depemdent ComnPrice.                     \n");
    printf("                               8.SeqPlanes Depemdent Otd.                     \n");
    printf("                               9.SeqPlanes Depemdent Type.                     \n");
    printf("                               10.SeqPlanes Depemdent SeatLeft.                     \n");
    printf("                               11.exit to exit.                     \n");
    
        //    ============================================================================================

    printf("==========================================input arrgument====================================\n");
    //printf("==========================================you can also input 11 to exit=======================\n");
    while( 1 == scanf("%d",&op) && (op > 0 || op <12)){
     if( op == 11 )
     {
         PassengerUi(fi, pi);
         return  FUNC_ERR;
     }
    // system("clear");
    switch (op) {
        case 1:FlightSeqDpdFlightName(fi) ;CL();DisplayFlightInfo(fi);SeqUi(fi,pi);break;
        case 2:FlightSeqDpdFrom(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi);break;
        case 3:FlightSeqDpdTo(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 4:FlightSeqDpdDepart(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 5:FlightSeqDpdArrive(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 6:FlightSeqDpdFirstPrice(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 7:FlightSeqDpdComnPrice(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 8:FlightSeqDpdOtd(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 9:FlightSeqDpdType(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 10:FlightSeqDpdSeatLeft(fi);CL();DisplayFlightInfo(fi);SeqUi(fi,pi );break;
        case 11:PassengerUi(fi, pi);break;
        default:SeqUi(fi,pi );
            break;
    }
    }
    getchar();
    SeqUi(fi,pi);
    return FUNC_OK;
}

t_sint32 Login (FlightInformation *fi, PassengerInformation *pi)  //登陆函数 密码为1234

{
    t_int8 *input11 = NULL;
    input11 = Malloc(t_int8, 20);
    printf("=============================Input you passcode to logoin===============================\n");
    printf("=============================Default is 1234============================================\n");
    scanf("%s",input11);
    getchar();
    while(strcmp(input11, "1234") != 0)
    {
        printf("=============================Error Input ===========================================\n ");
        scanf("%s",input11);
    }
    printf("=============================Logion please wait =========================================\n");
sleep(2);
    return FUNC_OK;
}
t_sint32 LoginPass (FlightInformation *fi, PassengerInformation *pi)  //登陆函数 密码为1111

{
    t_int8 *input11 = NULL;
    input11 = Malloc(t_int8, 20);
    printf("=============================Input you passcode to logoin===============================\n");
     printf("=============================Default is 1111============================================\n");
    scanf("%s",input11);
    getchar();
    while(strcmp(input11, "1111") != 0)
    {
        printf("=============================Error Input ===========================================\n ");
        scanf("%s",input11);
    }
    printf("=============================Logion please wait =========================================\n");
    sleep(2);
    return FUNC_OK;
}

void RamdonInsert (FlightInformation *fi )       //随机插入航班信息 显示有问题
{
    for(t_sint32 i = 0 ; i< 30;i++)
    {
        t_sint32 rd = rand();
    
        t_int8 Name[9][20] = {"CA2245","BB3213","UA4233","FD3242","CG1322","GB3422","CH8242","NY5242","BB6242"};
        t_int8 From[8][20] = {"New York","Houston","Oxford","Cambridge","Tokyo","Osaka","Nagoya","kobe"};
        t_int8 To[8][20] = {"Paris","London","Hong Kong","San Francisco","Denver","Montgomery","Atlanta","Lima"};
        t_sint32 Depart[17]= {1233,2233,1124,823,711,2245,533,122,1322,1466,622,722,522,618,1122,2244,2134};
        t_int8 Type[9][20] = {"Boei777","Boei747","A330","Boei717","A370","Boei737","Boei727","Boei787","A330"};
        //t_int8 *n = strcat("ca", Name[rd%9]);
     InsertFight(fi,Name[rd%8],From[rd%8],To[rd%8],Depart[rd%17], Depart[rd%17], rd%5000, rd%3000, rd%40, Type[rd%9], rd%30,"CCCC");
      printf("%s  ",Name[rd%9]);
      //  printf("%s  ",From[rd%8]);
      //  printf("%s  ", To[rd%8]);
      //  printf("%d  ",Depart[rd%17]);
       // printf("%d  ",Depart[rd%17]);
       // printf("%d  ",rd%5000);
      //  printf("%d  ",rd%3000);
       // printf("%d  ",rd%40);
       // printf("%s  ",Type[rd%9]);
      //  printf("%d  \n",rd%30);
        
        
        
        
        //printf("%d,%d \n ",rd%17,Depart[rd%17]);
        //printf("%d,%d \n ",Depart[rd%17],Depart[rd%17]);
    }
}
