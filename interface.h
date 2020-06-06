//
//  interface.h
//  1_内核链表
//
//  Created by 张嘉豪 on 2020/3/26.
//  Copyright © 2020 张嘉豪. All rights reserved.
//

#ifndef interface_h
#define interface_h
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
//#include "passager.h"
#include <time.h>
#define FUNC_OK     0
#define FUNC_ERR    1

#define DEBUG_MSG(x)    printf ("[DEBUG][%s][%d]:",__FUNCTION__,__LINE__); printf(x)
#define INFO_MSG(x)     printf ("[INFO.][%s][%d]:",__FUNCTION__,__LINE__); printf(x)
#define ERROR_MSG(x)    printf ("[ERROR][%s][%d]:",__FUNCTION__,__LINE__); printf(x)

#define Malloc(type,len)    (type*)malloc(sizeof(type) * len)

typedef signed int    t_sint32;
typedef char t_int8;
typedef  float t_float32;
struct  PassengerInformation {
    t_sint32 IsBuy;
    t_int8* Name;
    t_sint32 Seat;
    t_int8* FightName;
    t_sint32 AccoutBalance;
    struct list_head node;
};
typedef struct PassengerInformation PassengerInformation;

struct FlightInformation {
    t_int8      *FighhtName;
 
    t_int8      *From;
    t_int8      *To;
    t_sint32    Depart;
    t_sint32    Arrive;
    t_sint32    FirstPrice;
    t_sint32    ComnPrice;
    t_float32   Correctness;
    t_int8      *AircraftTypeT;
    t_sint32    SeatLeft;
    t_int8      *AirLine;
    struct list_head node;
    t_int8 Seat[30][20] ;
};
typedef struct FlightInformation FlightInformation;
void PrintM(t_int8 * input );
void RamdonInsert (FlightInformation *fi );
t_sint32 InitFI (FlightInformation **fi,t_int8 *FighhtName,t_int8 *From,t_int8 *To,t_sint32 Depart,t_sint32 Arrive,t_sint32 FirstPrice,t_sint32 ComnPrice,t_float32 Correctness,t_int8 *AircraftTypeT,t_sint32 SeatLeft,t_int8      *AirLine );
t_sint32 InitFIHead (FlightInformation **fi);
t_sint32 InsertFight(FlightInformation *fi,t_int8 *FighhtName,t_int8 *From,t_int8 *To,t_sint32 Depart,t_sint32 Arrive,t_sint32 FirstPrice,t_sint32 ComnPrice,t_float32 Correctness,t_int8 *AircraftTypeT,t_sint32 SeatLeft ,t_int8      *AirLine);
t_sint32 ListFlight(FlightInformation *fi);
void DisplayFlightInfo(FlightInformation *fi);
void DisplaySinglePlane(FlightInformation *pcur);
void Welcome(t_sint32 input,FlightInformation *fi, PassengerInformation *pi);
t_sint32 SortList(FlightInformation *fi,t_int8 *key);
void CL(void);
t_sint32 SearchDpdKey(FlightInformation *head, t_int8 *input);
t_sint32 DeleteDpdName(FlightInformation *head, t_int8 *input);
t_sint32 DeleteDpdFrom(FlightInformation *head, t_int8 *input);
t_sint32 DeleteDpdTo(FlightInformation *head, t_int8 *input);
t_sint32 BoardingAttention(FlightInformation *fi);
t_sint32  PlaneAutoDelete(FlightInformation *fi);
t_sint32 GetFlightAddr(FlightInformation *fi,t_int8 *input,FlightInformation **loc);


t_sint32 InitPass(PassengerInformation **pi ,t_sint32 IsBuy,t_sint32 Seat,t_int8* Name,t_int8* FightName,t_sint32 AccoutBalance);
t_int8   InitPassHead(PassengerInformation **pi);
t_sint32 PlaneStats(FlightInformation *fi,t_int8 *name);
t_sint32 ListPi(PassengerInformation *pi);
t_sint32 PassengerUi(FlightInformation *fi,PassengerInformation *pi);
t_sint32 BuyUi(FlightInformation *fi,PassengerInformation *pi, PassengerInformation *loc);
t_sint32 ChangeUi(FlightInformation *fi,PassengerInformation *pi, PassengerInformation *loc);
t_sint32 RefundUi(FlightInformation *fi,PassengerInformation *pi, PassengerInformation *loc);
t_sint32 BuyTicket(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_sint32 input);
t_sint32 InsertPassanger(PassengerInformation *pi,t_sint32 IsBuy,t_sint32 Seat,t_int8* Name,t_int8* FightName,t_sint32 AccoutBalance);
t_sint32 ChangeTicket(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_int8 *newPlane,t_sint32 input);
t_sint32 RefundTickets(FlightInformation *fi,PassengerInformation *pi,t_int8 *Name,t_int8 *PlaneName,t_sint32 input);
t_sint32 FlightSeqDpdFlightName(FlightInformation *fi);
t_sint32 FlightSeqDpdFrom(FlightInformation *fi);
t_sint32 FlightSeqDpdTo(FlightInformation *fi);
t_sint32 FlightSeqDpdDepart(FlightInformation *fi);
t_sint32 FlightSeqDpdArrive(FlightInformation *fi);
t_sint32 FlightSeqDpdFirstPrice(FlightInformation *fi);
t_sint32 FlightSeqDpdComnPrice(FlightInformation *fi);
t_sint32 FlightSeqDpdOtd(FlightInformation *fi);
t_sint32 FlightSeqDpdType(FlightInformation *fi);
t_sint32 FlightSeqDpdSeatLeft(FlightInformation *fi);
t_sint32 SeqUi(FlightInformation *fi,PassengerInformation *pi );




void admin(FlightInformation *fi,PassengerInformation *pi);
//void PassAnger(FlightInformation *fi,PassengerInformation *pi);
void DeleteFlight(FlightInformation *fi,PassengerInformation *pi);
void ModifyFlight(FlightInformation *fi,PassengerInformation *pi);
void DeleteFlightDpdItem(FlightInformation *fi,PassengerInformation *pi);
t_sint32 GetPassAddr(PassengerInformation *pi ,t_int8 *input ,PassengerInformation **loc);
t_sint32 DelFlightdDpdPlaneName(FlightInformation *fi,t_int8 *input);
t_sint32 DelFlightdDpdFrom(FlightInformation *fi,t_int8 *input);
t_sint32 DelFlightdDpdTo(FlightInformation *fi,t_int8 *input);
t_sint32 DelFlightdDpdDepart(FlightInformation *fi,t_sint32 input);
t_sint32 DelFlightdDpdArrive(FlightInformation *fi,t_sint32 input);
t_sint32 DelFlightdDpdFirstPrice(FlightInformation *fi,t_sint32 input);
t_sint32 DelFlightdDpdComnPrice(FlightInformation *fi,t_sint32 input);
t_sint32 DelFlightdDpdOtd (FlightInformation *fi,t_float32 input);
t_sint32 DelFlightdDpdType(FlightInformation *fi,t_int8 *input);
t_sint32 DelFlightdDpdSeatLeft(FlightInformation *fi,t_sint32 input);
t_sint32 SearchDpdFligtName(FlightInformation *fi, t_int8 *input);
t_sint32 SearchDpdFrom(FlightInformation *fi, t_int8 *input);
t_sint32 SearchDpdTo(FlightInformation *fi, t_int8 *input);
t_sint32 SearchDpdType(FlightInformation *fi, t_int8 *input);
t_sint32 SearchDpdDepart(FlightInformation *fi, t_sint32 input);
t_sint32 SearchDpdArrive(FlightInformation *fi, t_sint32 input);
t_sint32 SearchUi(FlightInformation *fi, PassengerInformation *pi );




t_sint32 LoginPass (FlightInformation *fi, PassengerInformation *pi);
t_sint32 Login(FlightInformation *fi,PassengerInformation *pi);
#endif /* interface_h */
