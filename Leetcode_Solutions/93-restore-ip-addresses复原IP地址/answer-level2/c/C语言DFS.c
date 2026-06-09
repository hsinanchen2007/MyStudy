### 解题思路
常规思路，DFS。

### 代码

```c
#define         MAX_SIZE        200
#define         MAX_IP_LEN      20
#define         MIN_IP_LEN      4
#define         MAX_TYPE_SIZE   100
#define         MAX_IP_VALUE    255
#define         NUM_4           4
#define         NUM_3           3
#define         NUM_2           2
#define         NUM_1           1
#define         CHECK_OK        1
#define         CHECK_FAIL      0

char *GetAddr(void)
{
    char        *rt     = NULL;

    rt          = (char *)malloc(MAX_IP_LEN);
    if (rt == NULL) {
        return rt;
    }
    memset(rt, 0, MAX_IP_LEN);
    return rt;
}

int CheckIp(char *cur, int curLen)
{
    int         num     = 0;

    for (int loop = 0; loop < curLen; loop++) {
        num         = 10 * num + (cur[loop] - '0');
    }

    if (num > MAX_IP_VALUE) {
        return CHECK_FAIL;
    }

    if ((cur[0] == '0') && (num != 0)) {
        return CHECK_FAIL;
    }

    if ((num == 0) && (curLen > 1)) {
        return CHECK_FAIL;
    }

    return CHECK_OK;
}

void FreeNode(char **rslt, int len)
{
    if (rslt == NULL) {
        return;
    }

    for (int loop = 0; loop < len; loop++) {
        if (rslt[loop] != NULL) {
            free(rslt[loop]);
            rslt[loop]      = NULL;
        }
    }
}

void LoopFindIp(char **rslt, char *s, int *len, int flag)
{
    int                 loop = 0;
    char                cur[MIN_IP_LEN];
    int                 curLen     = 0;
    char                **rt        = NULL;
    int                 rtLen       = 0;
    char                *temp       = NULL;

    if (strlen(s) <= 0) {
        return;
    }

    if ((flag == NUM_3) && (((int)strlen(s) > NUM_3 * NUM_3) || ((int)strlen(s) < NUM_3))) {
        return;
    }

    if ((flag == NUM_2) && (((int)strlen(s) > NUM_2 * NUM_3) || ((int)strlen(s) < NUM_2))) {
        return;
    }

    if ((flag == NUM_1) && (((int)strlen(s) > NUM_1 * NUM_3) || ((int)strlen(s) < NUM_1))) {
        return;
    }

    if (flag == NUM_1) {
        if (CheckIp(s, (int)strlen(s)) == CHECK_OK) {
            rslt[*len]      = GetAddr();
            if (rslt[*len] == NULL) {
                return;
            }
            rslt[*len][0]       = '.';
            memcpy(&rslt[*len][1], s, strlen(s));
            (*len)++;
        }
        return;
    }

    rt            = (char **)malloc(sizeof(char *) * MAX_TYPE_SIZE);
    if (rt == NULL) {
        return;
    }
    memset(rt, 0, sizeof(char *) * MAX_TYPE_SIZE);
    memset(cur, 0, sizeof(cur));

    while (s[loop] != '\0') {
        if (curLen >= NUM_3) {
            break;
        }
        cur[curLen] = s[loop];
        curLen++;
        if (CheckIp(cur, curLen) == CHECK_OK) {
            LoopFindIp(rt, &s[loop + 1], &rtLen, flag - 1);
            for (int i = 0; i < rtLen; i++) {
                rslt[*len]      = GetAddr();
                if (rslt[*len] == NULL) {
                    FreeNode(rt, rtLen);
                    free(rt);
                    return;
                }

                if (flag < NUM_4) {
                    rslt[*len][0]       = '.';
                    memcpy(&rslt[*len][1], cur, curLen);
                    memcpy(&rslt[*len][1 + curLen], rt[i], strlen(rt[i]));  
                } else {
                    memcpy(&rslt[*len][0], cur, curLen);
                    memcpy(&rslt[*len][curLen], rt[i], strlen(rt[i]));
                }
                (*len)++;
            }

            FreeNode(rt, rtLen);
            rtLen       = 0;
            
        } else {
            break;
        }

        loop++;
    }

    FreeNode(rt, rtLen);
    free(rt);

    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize)
{
    char            **rslt      = NULL;
    int               len       = 0;

    rslt            = (char **)malloc(sizeof(char *) * MAX_TYPE_SIZE);
    if (rslt == NULL) {
        return NULL;
    }
    memset(rslt, 0, sizeof(char *) * MAX_TYPE_SIZE);

    if (returnSize == NULL) {
        return rslt;
    }

    *returnSize     = 0;
    if (s == NULL) {
        return rslt;
    }

    if (strlen(s) < MIN_IP_LEN) {
        return rslt;
    }

    if (strlen(s) > MIN_IP_LEN * NUM_3) {
        return rslt;
    }  

    LoopFindIp(rslt, s, &len, NUM_4);

    *returnSize          = len;

    return rslt;
}
```