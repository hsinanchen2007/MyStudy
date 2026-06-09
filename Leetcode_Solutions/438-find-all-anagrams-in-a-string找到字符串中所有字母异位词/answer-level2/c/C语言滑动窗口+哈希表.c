### 解题思路
使用哈希表创建字母易位比较基线
按照匹配的字符串长度建立滑动窗口，窗口内的哈希值和基线比较，匹配上表示属于异位子串
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXSIZE 26
#define PRINTF // printf
bool HashMatch(int *pSrcHash, int *pDstHash) {
    bool bRet = true;
    for(int i = 0; i < MAXSIZE; i++){
        if (pSrcHash[i] != pDstHash[i]) {
            bRet = false;
            break;
        }
    }
    return bRet;
}
int* findAnagrams(char * s, char * p, int* returnSize){
    int pLen = strlen(p);
    int sLen = strlen(s);
    int *pCurHash = (int *)malloc(MAXSIZE * sizeof(int));
    int *pMaskHash = (int *)malloc(MAXSIZE * sizeof(int));
    memset(pMaskHash, 0, (MAXSIZE * sizeof(int)));
    memset(pCurHash, 0, (MAXSIZE * sizeof(int)));
    for(int i = 0; i < pLen; i++) {
        pMaskHash[(p[i] - 'a')]++;
    }
    int *pRet = (int *)malloc(sLen * sizeof(int));
    int retSize = 0;
    for (int i = 0; i < sLen; i++) {
        pCurHash[(s[i] - 'a')]++;
        if (i < (pLen - 1)) {
            continue;
        }
        if (i >= pLen) {
            pCurHash[(s[i - pLen] - 'a')]--;
        }
        if(HashMatch(pCurHash, pMaskHash) == true){
            pRet[retSize] = (i - (pLen - 1));
            retSize++;
        }
    }
    *returnSize = retSize;
    free(pCurHash);
    free(pMaskHash);
    return pRet;
}
```