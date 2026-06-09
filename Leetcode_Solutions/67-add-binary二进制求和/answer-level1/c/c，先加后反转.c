执行用时 : 0 ms, 在所有 C 提交中击败了 100.00% 的用户
内存消耗 : 5.3 MB, 在所有 C 提交中击败了 100.00% 的用户

先加后反转
```c
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

static uint8_t is_carry(int a, int b, int carry, char* rst);

char * addBinary(char * a, char * b){
    int alens = strlen(a);
    int blens = strlen(b);
    int clens = alens > blens ? alens+1: blens+1;
    int ida = alens-1, idb = blens-1, idc=0;
    int carry = 0;
    char aval = a[ida], bval = b[idb];

    char* c = (char*)malloc(sizeof(char)*clens);

    while(1)
    {
        carry = is_carry(aval-'0', bval-'0', carry, (c+idc));
        // printf("carry: %d, ida: %d, idb: %d, idc: %d\n", carry, ida, idb, idc);
        ida--;
        idb--;
        if (ida < 0 && idb < 0 && carry == 0) break;
        if (ida < 0) aval = '0';
        else aval = a[ida];
        if (idb < 0) bval = '0';
        else bval = b[idb];
        idc++;
    }

    char *ret = (char*)malloc(sizeof(char)*(idc+1+1));
    for (int idx=0; idx < idc+1; idx++) {
        ret[idx] = c[idc-idx];
    }
    ret[idc+1] = '\0'; 
    free(c);
    return ret;
}

uint8_t is_carry(int a, int b, int carry, char* rst)
{
    int ret = 0;
    // printf("a: %d, b: %d, carry: %d\n", a, b, carry);
    int c = a + b + carry;
    *rst = c % 2 + '0';
    // printf("rst: %c\n", *rst);
    if (c >= 2) return ret = 1;
    return ret;
}
```
