### 解题思路
回溯算法：套用模板
void backtrace(int i, int n, other parameters) 
{
    if (i == n)
    {
        if (valid) {
            add record; 
        } else {
            return;
        }
    }

    for (next ans in position i) {
        /* 有效性检查 */
 
        /* 保存对应dotindex的place值 */
        pstAddrRecord->dotIndexBuf[dotIndex] = k;

        /* 进一步深度优先搜索 */
        backstace(i + 1, n, other parameters);
    

        /* 回溯：还原dotIndex对应的place值 */
        pstAddrRecord->dotIndexBuf[dotIndex] = 0;
    }
}


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * auther :[生哥]
 */

#define MAX_RECORD_SIZE (100)
 typedef struct tag_addrRecord {
    char *buffer;
    char **pRecord;
    int count;
    int dotIndexBuf[4];
 }AddrRecord_S;


int InitAddrRecord(AddrRecord_S *pstAddrRecord, int len) 
{
    pstAddrRecord->buffer = malloc(sizeof(char) * (len + 4));
    if (pstAddrRecord->buffer == NULL) {
        return -1;
    }

    pstAddrRecord->count = 0;
    pstAddrRecord->pRecord = malloc(sizeof(char *) * (MAX_RECORD_SIZE));
    if (pstAddrRecord->pRecord == NULL) {
        free(pstAddrRecord->buffer);
        return -1;
    }

    memset(pstAddrRecord->dotIndexBuf, 0, sizeof(pstAddrRecord->dotIndexBuf));

    return 0;
}


bool checkStringIsInvalid(int leftPlace, int rightPlace, char *s)
{
    int i;
    int result = 0;

    if (rightPlace - leftPlace > 3 || leftPlace > rightPlace || rightPlace == 0) {
        return false;
    }

    if (s[leftPlace] == '0' && (rightPlace - leftPlace) > 1) {
        return false;
    }

    for (i = leftPlace; i < rightPlace; i++) {
        result = result * 10 + (s[i] - '0');
    }

    if (result > 255) {
        return false;
    }
    printf("%s, left is %d, right is %d.\n", s, leftPlace, rightPlace);

    return true;
}

void CopyString(char *dest, char *src, int *dotIndexBuf, int len)
{
    int i, j;
    j = 0;

    for (i = 0; i < len; i++) {
        if (i == dotIndexBuf[0] || i == dotIndexBuf[1] || i == dotIndexBuf[2]) {
            dest[j++] = '.';
        }
        dest[j++] = src[i];
    }
    dest[j] = '\0';
    return;
}

int backTrace(char *s, int len, int dotIndex, int place, AddrRecord_S *pstAddrRecord)
{
    bool isInvalid;
    int k;
    int ret;

    if (dotIndex == 3) {        
        printf ("dotIndexBuf[3] = %d\n", place);
        /* 校验最后一串字符的有效性 */
        isInvalid = checkStringIsInvalid(pstAddrRecord->dotIndexBuf[2], len, s);
        if (isInvalid == true) {            
            for (k = 0; k < 3; k++) {
                printf("%d ", pstAddrRecord->dotIndexBuf[k]);
            }
            printf("\n");
            pstAddrRecord->pRecord[pstAddrRecord->count] = (char *)malloc(sizeof(char) * (len + 4));
            if (pstAddrRecord->pRecord[pstAddrRecord->count] == NULL) {
                return -1;
            }
            CopyString(pstAddrRecord->pRecord[pstAddrRecord->count], s, pstAddrRecord->dotIndexBuf, len);
            printf ("%d: %s\n", pstAddrRecord->count, pstAddrRecord->pRecord[pstAddrRecord->count]);
            pstAddrRecord->count++;
        } else {
            return -1;
        }
    }

    for (k = place; k < len && k < (place + 3); k++) {
        /* 根据dotindex和place计算字符串的有效性,无效则直接返回，不进行深度搜索 */
        if (dotIndex == 0) {
            isInvalid = checkStringIsInvalid(0, k, s);
        } else {
            isInvalid = checkStringIsInvalid(pstAddrRecord->dotIndexBuf[dotIndex - 1], k, s);
        }

        if (isInvalid == false) {
            return -1;
        }
        
        /* 保存对应dotindex的place值 */
        pstAddrRecord->dotIndexBuf[dotIndex] = k;
        printf ("dotIndexBuf[%d] = %d\n", dotIndex, k);

        /* 进一步深度优先搜索 */
        ret = backTrace(s, len, dotIndex + 1, k + 1, pstAddrRecord);
    

        /* 回溯：还原dotIndex对应的place值 */
        pstAddrRecord->dotIndexBuf[dotIndex] = 0;
    }

    return 0;
}


char ** restoreIpAddresses(char * s, int* returnSize){
    AddrRecord_S stAddrRecord;
    int len;
    int i;
    int ret;

    if (s == NULL || returnSize == NULL) {
        return NULL;
    }


    len = strlen(s);
    if (len < 4 || len > 12) {
        *returnSize = 0;
        return NULL;
    }
    
    ret = InitAddrRecord(&stAddrRecord, len);
    if (ret != 0) {
        return NULL;
    }

    backTrace(s, len, 0, 1, &stAddrRecord);

    *returnSize = stAddrRecord.count;
    return stAddrRecord.pRecord;
}
```