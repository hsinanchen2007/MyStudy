### 解题思路
此处撰写解题思路

### 代码

```c
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define STRING_LEN_MAX  32

#define DEBUG
#ifdef DEBUG
#define LOG(...)    printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int FindOneBitPos(unsigned int num)
{
    int pos = 0;

    while (pos <= 32) {
        if (num & (1 << pos)) {
            break;
        }
        pos++;
    }

    return pos;
}

// 整数转成字符串
char *ToString(int num, char *buf)
{
    char stack[32];
    int tail = -1;
    int res;
    char resCh;

    char *start = buf;

    // LOG("ToString: %d\n", num);

    while (num >= 10) {
        res = num % 10;
        num /= 10;
        resCh = '0' + res;
        tail++;
        stack[tail] = resCh;
    }

    tail++;
    stack[tail] = '0' + num;   

    while (tail >= 0) {
        *buf = stack[tail];
        tail--;
        buf++;
    }
    *buf = '\0';

    // LOG("ToString: %s\n", start);

    return start;
}

char **g_cidrRes;
int g_cidrCnt = 0;

void MakeCidr(unsigned int ipNum, int subNum)
{
    int i = 3;
    int len = 0;
    char tmp[STRING_LEN_MAX];

    g_cidrRes[g_cidrCnt] = malloc(STRING_LEN_MAX);

    while (i >= 0) {
        ToString((int)(ipNum >> (i * 8)) & 0xFF, tmp);
        strcpy(g_cidrRes[g_cidrCnt] + len, tmp);
        len += strlen(tmp);
        if (i != 0) {
            g_cidrRes[g_cidrCnt][len] = '.';
            len++;
        } else {
            g_cidrRes[g_cidrCnt][len] = '/';
            len++;
            ToString(subNum, tmp);
            strcpy(g_cidrRes[g_cidrCnt] + len, tmp);             
        }
        i--;
    }

    LOG("MakeCidr:%s\n", g_cidrRes[g_cidrCnt]);
    g_cidrCnt++;
}

void LastCidr(unsigned int ipNum, int n)
{
    int maxBitLen = 0;
    int i = 0;

    if (n <= 0) {
        return;
    }

    while ((1 << i) < n) {
        i++;
    }

    LOG("LastCidr get i = %d\n", i);

    if ((1 << i) == n) {
        // MakeCidr(ipNum, 32 - (n - i) + 1);
        MakeCidr(ipNum, 32 - i);
    } else {
        MakeCidr(ipNum, 32 - (i - 1));
        ipNum += 1 << (i - 1);
        LastCidr(ipNum, n - (1 << (i - 1)));
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** ipToCIDR(char * ip, int n, int* returnSize){
    int i;
    unsigned int ipNum = 0;
    unsigned int tmpNum;

    char *tmp = strtok(ip, ".");
    i = 3;
    while (tmp != NULL && i >= 0) {
        tmpNum = ((unsigned int)atoi(tmp) & 0xFF) << (i * 8);
        ipNum = ipNum & ~((unsigned int)0xFF << (i * 8)) | tmpNum;
        tmp = strtok(NULL, ".");
        i--;
    }
    
    // LOG("ip:0x%x\n", ipNum);
    g_cidrRes = malloc(sizeof(char *) * n);
    g_cidrCnt = 0;

    i = 0;
    while (i < n) {
        int pos = FindOneBitPos(ipNum);
        LOG("ipNum = 0x%x, pos = %d\n", ipNum, pos);
        if (((1 << pos) + i) <= n) {
            MakeCidr(ipNum, 32 - pos);
            ipNum += (1 << pos);
            i += (1 << pos);
        } else {
            tmpNum = n - i;  // 还剩tmpNum，如果是2的次幂，则只有一个，否则找出最大的n，使用2^n < tmpNum
            LOG("tmp num is %d\n", tmpNum);
            LastCidr(ipNum, tmpNum);
            i = n; 
        }
    }

    *returnSize = g_cidrCnt;

    return g_cidrRes;
}
```