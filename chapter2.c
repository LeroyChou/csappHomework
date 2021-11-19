#include "chapter2.h"
/*2.63*/
unsigned srl(unsigned x, int k){
    /* Perform shift arithemtically */
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) << 3;
    int mask = (int)-1 << (w - k);
    return xsra & ~mask;
}

/*create diffrent masks according to the first bit of x*/
int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) << 3;
    int mask = (-1) << (w - k);
    int h = (1 << (w - 1)) & x;
    mask &= (!h) - 1;
    return mask | xsrl;

}

/*2.64*/
/*create mask*/
int any_odd_one(unsigned x) {
    return (0xaaaaaaaa & x) != 0;
}

/*2.65*/
/*add all bits to last bit*/
int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x&0x1;
}

/*2.66*/
int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x && 1);
}

/*2.67*/
int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

/*2.68*/
int lower_one_mask(int n) {
    int x = (int) -1 << n - 1 << 1;
    return ~x;
}

/*2.69*/
unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    int tail = x >> (w - n - 1) >> 1;
    int head = x << n;
    return head | tail;
}

/*2.70*/
int fit_bits(int x, int n){
  int w=  sizeof(int) << 3;
  int offset = w - n;
  return (x << offset >> offset) == x;
}

/*2.71*/
int xbyte (packed_t word, int bytenum) {
    return (int) word << (24 - (bytenum << 3)) >> 24; // 要将word强制类型转换为int
}


/*2.72*/
void copy_int (int val, void *buf, int maxbytes) {
    if (maxbytes >= sizeof(val)){
        memcpy(buf, &val, sizeof(val));
    }
}

/*2.73*/
int saturating_add(int x, int y){
    int mask = INT_MIN;
    int sum = x + y;
    int pos_over = !(x & mask) && !(y  & mask) && sum & mask;
    int neg_over = (x & mask) && (y & mask)  && !(sum & mask);
    pos_over && (sum = INT_MAX) || neg_over && (sum = INT_MIN);
    return sum;

}

/*2.74*/
int tsub_ok(int x, int y) { 
    int mask = INT_MIN;
    int res = x - y;
    int pos_over = !(x & mask) && (y & mask) && (res & mask);
    int neg_over = (x & mask) && !(y & mask) && !(res & mask);
    return (!pos_over) && (!neg_over);
}

/*2.75*/
/*lib function here*/
int signed_high_prod(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

/*function implemented here*/
unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int w = sizeof(unsigned) << 3;
    unsigned x_sig = x >> w;
    unsigned y_sig = y >> w;
    int high_prod = signed_high_prod(x, y);
    return high_prod + x * y_sig + y * x_sig;
}

/*2.76*/
void *self_calloc(size_t nmemb, size_t size){  // Another name to avoid conflicting
    if (nmemb == 0 || size == 0) {
        return NULL;
    }
    size_t totalSize = nmemb * size;  // Might cause overflow here!!
    if (totalSize / size == nmemb) {
        void* p = malloc(totalSize);
        if (p == NULL) {
            return NULL;
        }         
        memset(p, 0, totalSize);
        return p;
    }
    return NULL;
}

/*2.77*/
void mul(){
    int x = 3;
    int res;
/*K = 17*/
    res = (x << 4) + x ;  //注意移位操作的优先级比较低， 应该加上括号
    printf("%d\n", res);
/*K = -7*/
    res = x - (x << 3);
    printf("%d\n", res);
/*K = 60*/
    res =  (x << 6) - (x << 2);
    printf("%d\n", res);
/*K = -112*/
    res = (x << 4) - (x << 7);
    printf("%d\n", res);
}


/*2.78*/
int divide_power2(int x, int k){
    int mask = INT_MIN;
    !(mask & x) && (x = x >> k) || (mask & x) && (x = (x + (1 << k) - 1) >> k);
    return x;
}

/*2.79*/
int mul3div4(int x) {
    x = (x << 1) + x;
    return divide_power2(x, 2);
}

/*2.80*/
int threefourths(int x){
    int onefourth = divide_power2(x, 2);
    int bias = x - (onefourth << 2);
    bias = (bias << 1) + bias;
    bias = divide_power2(bias, 2);
    return ((onefourth << 1) + onefourth) + bias;
}

/*2.81*/
void generate(){
/*A*/
    int x = (int) -1 << k;
/*B*/
    int y = ~(-1 << k) << j; 
}
























