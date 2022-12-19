### 解题思路
![image.png](https://pic.leetcode-cn.com/ef6808f8629e9fc760c898d7fd51372aa569b9a6a5b099c131ae01b2af9edcb3-image.png)
分割：子串连起来还是s, 单个字符肯定是回文
每个位置i分割索引的范围： i ~ len - 1, 每个位置都有这么多选择，如果当前选择是有效的回文就递归选择下去，否则选项下一个可能范围


### 代码

```c
 bool CheckHuiWenStr(char *l, char *r)
 {
     char *pl = l;
     char *pr = r;
     while (pl < pr) {
         if (*pl != *pr) {
             return false;
         }
         pl++;
         pr--;
     }

     return true;
 }

 void Dfs(char *s, int srcLen, int sId, char ***retChr, int *returnSize, char *recBuf, 
    int recBufId,char **recChar, int recCharCount, int **returnColumnSizes)
 {
    if (sId == srcLen) {
        //printf("sId:%d recCharCount:%d returnSize:%d\n", sId, recCharCount, *returnSize);
        //已全部选择完成了1次分割，记录结果
        (*returnColumnSizes)[*returnSize] = recCharCount;
        retChr[*returnSize] = malloc(sizeof(char *) * recCharCount);
        int subLen;
        for (int i = 0; i < recCharCount; i++) {
            subLen = strlen(recChar[i]);
            retChr[*returnSize][i] = malloc(sizeof(char) * subLen + 1);
            strcpy(retChr[*returnSize][i], recChar[i]);
            retChr[*returnSize][i][subLen] = '\0';
            //printf("%s\n", retChr[*returnSize][i]);
        }

        *returnSize += 1;
        return;
    }

    char *l, *r;
    l = s + sId; //left
    int backRecBufId = recBufId;
    for (int i = sId; i < srcLen; i++) {
        r = s + i;//right
        //printf("start i:%d l:%c r：%c recBufId:%d\n", i, *l, *r, recBufId);
        if (!CheckHuiWenStr(l, r)) {
            // printf("no huiwen\n");
            continue;
        }
        //printf("is huiwen ok\n");
        //拷贝回文子串到recBuf的recBufId位置
        strncpy(recBuf + recBufId, l, r - l + 1);
        recChar[recCharCount] = recBuf + recBufId; //记录该回文子串
        recBufId += r - l + 1;
        recBuf[recBufId++] = '\0';

        //printf("sId:%d i:%d sub str: %s\n", sId, i, recChar[recCharCount]);

        //当前l~r字符是回文，继续i位置之后的选择后面的字符
        Dfs(s, srcLen, i + 1, retChr, returnSize, recBuf, recBufId, recChar, recCharCount + 1, returnColumnSizes);

        recBufId = backRecBufId;
    }
 }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    //分割：子串连起来还是s, 单个字符肯定是回文
    //每个位置i分割索引的范围： i ~ len - 1, 每个位置都有这么多选择，如果当前选择是有效的回文就递归选择下去，否则选项下一个可能
    char *** retChr = malloc(sizeof(char **) * 1024);
    *returnColumnSizes = malloc(sizeof(int) * 1024);
    *returnSize = 0;
    int srcLen = strlen(s);
    if (srcLen == 1) {
        *returnSize = 1;
        *returnColumnSizes[0] = 1;
        retChr[0] = malloc(sizeof(char *) * srcLen);
        retChr[0][0] = malloc(sizeof(char) * 2);
        retChr[0][0][0] = s[0];
        retChr[0][0][1] = '\0';
        return retChr;
    }

    char *recBuf = malloc(sizeof(char) * srcLen * 2);
    char **recChar = malloc(sizeof(char *) * srcLen);
    //sId: 当前从s里的哪个索引字符开始， 范围就是sId ~ len -1
    Dfs(s, srcLen, 0, retChr, returnSize, recBuf, 0, recChar, 0, returnColumnSizes);
    printf("returnSize:%d\n", *returnSize);

    free(recBuf);
    free(recChar);

    return retChr;
}
```