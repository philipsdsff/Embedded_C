/*
 * plateform_type.h
 *
 *  Created on: Dec 23, 2022
 *      Author: Philip
 */

#ifndef PLATEFORM_TYPE_H_
#define PLATEFORM_TYPE_H_



typedef _Bool 			boolean;

#define CPU_TYPE         CPU_TYPE_32
#define CPU_BIT_ORDER    MSB_FIRST
#define CPU_BYTE_ORDER   HIGH_BYTE_FIRST


////////////////////////signed//////////////////////////////////////////
typedef char       int8_t ;
typedef short      int16_t;
typedef int        int32_t;
typedef long long  int64_t;

typedef int8_t 			sint8 ;
typedef int16_t			sint16;
typedef int32_t			sint32;
typedef int64_t			sint64;

typedef volatile int8_t              vint8 ;
typedef volatile int16_t             vint16;
typedef volatile int32_t             vint32;
typedef volatile int64_t             vint64;

////////////////////////unsigned//////////////////////////////////////////


typedef unsigned char       uint8_t ;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;


typedef uint8_t 		uint8 ;
typedef uint16_t		uint16;
typedef uint32_t		uint32;
typedef uint64_t		uint64;


typedef volatile uint8_t              vuint8 ;
typedef volatile uint16_t             vuint16;
typedef volatile uint32_t             vuint32;
typedef volatile uint64_t             vuint64;



typedef float       float32;
typedef double      float64;


#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif


#endif PLATEFORM_TYPE_H_

