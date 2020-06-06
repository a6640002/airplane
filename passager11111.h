//
//  passager.h
//  airline
//
//  Created by li on 2020/4/3.
//  Copyright © 2020年 li. All rights reserved.
//

#ifndef passager_h
#define passager_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "interface.h"
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






















#endif /* passager_h */
