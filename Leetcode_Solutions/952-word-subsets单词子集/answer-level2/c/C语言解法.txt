### 解题思路
此处撰写解题思路
 思路： [update by 2020-3-29]
    1、刚开始用A中的每一个子串suba，与B中的每个子串进行遍历比较，比较算法用hash计数统计。如果suba都包含了B的子串字母，则suba就是通用的。 但是这种算法第45个用例会超时，时间复杂度为0(A*B*sublen).
    2、优化：先根据B的长度，定义一个数组merge[bsize][26], 先将B中每个字符串中字符出现的个数先统计保存在merge中。然后按照列，将每列中最大的字符个数cnt挑出来。将最大的个数放进一维数组hash[i] = cnt；然后用hash跟A中的字符串进行比较；时间复杂度y约为O(B*26) + O(A);
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*
    思路： [update by 2020-3-29]
    1、刚开始用A中的每一个子串suba，与B中的每个子串进行遍历比较，比较算法用hash计数统计。如果suba都包含了B的子串字母，则suba就是通用的。 但是这种算法第45个用例会超时，时间复杂度为0(A*B*sublen).
    2、优化：先根据B的长度，定义一个数组merge[bsize][26], 先将B中每个字符串中字符出现的个数先统计保存在merge中。然后按照列，将每列中最大的字符个数cnt挑出来。将最大的个数放进一维数组hash[i] = cnt；然后用hash跟A中的字符串进行比较；时间复杂度y约为O(B*26) + O(A);

 */
#define MAXLEN 26
#define ASUBSTRLEN 11
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int *g_includeflag = NULL;

int Isvalidparam(char **A, int ASize, char **B, int BSize, int *returnSize)
{
    if (returnSize == NULL) {
        return 0;
    }
    *returnSize = 0;
    int flag = (A == NULL) || (ASize < 1) || (B == NULL) || (BSize < 1);
    if (flag) {
        return 0;
    }
    return 1;
}

int IsAincludeB(char *stra, int alen, int *g_hashmerge)
{
    int hashtemp[MAXLEN] = {0};
    memcpy(hashtemp, g_hashmerge, sizeof(int) * MAXLEN);

    for (int i = 0; i < alen; i++) {
        int aval = stra[i] - 'a';
        if (hashtemp[aval] > 0) {
            hashtemp[aval]--;
        } 
    }
    // 看hash里面的值是否都为0，有一个不为零，就是不包含全部
    for (int i = 0; i < MAXLEN; i++) {
        if (hashtemp[i] != 0) {
            return false;
        }
    }
    return true;
}   

int JudgeAinclueB(char *stra, int alen, int *g_hashmerge)
{
    int ret = IsAincludeB(stra, alen, g_hashmerge);
    if (ret == 0) {
        return false;
    }
    return true;
}
char **wordSubsets(char **A, int ASize, char **B, int BSize, int* returnSize)
{
    int val = Isvalidparam(A, ASize, B, BSize, returnSize);
    if (val == 0) {
        return NULL;
    }
    g_includeflag = (int *)malloc(sizeof(int) * ASize);
    memset(g_includeflag, 0, sizeof(int) * ASize);

    int g_hashmerge[MAXLEN] = {0};
    // 先计算B中每个字母出现的最大次数, 每行最多只有26个小写字母
    int **bmaxcnt = (int **)malloc(sizeof(int *) * BSize);
    for (int i = 0; i < BSize; i++) {
        bmaxcnt[i] = (int *)malloc(sizeof(int) * MAXLEN);
        memset(bmaxcnt[i], 0, sizeof(int) * MAXLEN);
    } 
    for (int i = 0; i < BSize; i++) {
        int len = strlen(B[i]);
        for (int j = 0; j < len; j++) {
            int val = B[i][j] - 'a';
            bmaxcnt[i][val]++;
        }
    }
    // 按列来汇总，统计每列最大的个数字母
    for (int j = 0; j < MAXLEN; j++) {
        int maxj = 0;
        for (int i = 0; i < BSize; i++) {
            maxj = MAX(maxj, bmaxcnt[i][j]);
            g_hashmerge[j] = maxj;
        }
    }

    int novalidcnt = 0;
    for (int i = 0; i < ASize; i++) {
        char *str = A[i];
        int len = strlen(str);
        int ret = JudgeAinclueB(str, len, g_hashmerge);
        if (ret == 0) {
            g_includeflag[i] = 1;
            novalidcnt++;
        }
    }
    int validcnt = ASize - novalidcnt;
    if (validcnt == 0) {
        return NULL;
    }
    char **returnwords = (char **)malloc(sizeof(char *) * ASize);
    int index = 0;
    for (int i = 0; i < ASize; i++) {
        if (g_includeflag[i] == 0) {
            char *res = A[i];
            returnwords[index] = (char *)malloc(sizeof(char) * ASUBSTRLEN);
            memset(returnwords[index], 0, sizeof(char) * ASUBSTRLEN);
            strcpy(returnwords[index], res);
            index++;
        }
    }
    *returnSize = index;

    /* 释放内存 */
    free(g_includeflag);
    for (int i = 0; i < BSize; i++) {
        free(bmaxcnt[i]);
    } 
    return returnwords;
}






```