#ifndef __CHAPTER2_H__
#define __CHAPTER2_H__

#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

unsigned srl(unsigned x, int k);

int sra(int x, int k);

int any_odd_one(unsigned x);

int odd_ones(unsigned x);

int leftmost_one(unsigned);

int int_size_is_32();

int int_size_is_32_for_16bit();

int lower_one_mask(int n);

int fit_bits(int x, int n);

typedef unsigned packed_t;

int xbyte(packed_t , int);

void copy_int(int val, void *, int );

int saturating_add(int x, int y);

int saturating_add(int, int );

int tsub_ok(int, int);

unsigned unsigned_high_prod(unsigned x, unsigned y);

int signed_high_prod(int, int);

void *self_calloc(size_t, size_t);

void mul();

int divide_power2(int, int);

int mul3div4(int );

int threefourths(int);
#endif /*__CHAPTER2_H__*/
