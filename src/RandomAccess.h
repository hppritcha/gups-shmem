/* -*- mode: C; tab-width: 2; indent-tabs-mode: nil; -*- */

#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "config.h"

/* Random number generator */
#define POLY 0x0000000000000007UL
#define PERIOD 1317624576693539401L

/* Define 64-bit types and corresponding format strings for printf() and constants */
#define FSTR64 "%lld"
#define FSTRU64 "%llu"
#define ZERO64B 0LL

/* For timing */

__attribute__ ((unused))
static double RTSEC(void)
{
	struct timeval tp;
	gettimeofday (&tp, NULL);
	return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

extern int64_t starts (uint64_t);
extern uint64_t TotalMemOpt;
extern int NumUpdatesOpt;
extern double SHMEMGUPs;
extern double SHMEMRandomAccess_ErrorsFraction;
extern double SHMEMRandomAccess_time;
extern double SHMEMRandomAccess_CheckTime;
extern uint64_t *HPCC_Table;
extern int Failure;


#define HPCC_TRUE 1
#define HPCC_FALSE 0
#define HPCC_DONE 0

int SHMEMRandomAccess(void);
