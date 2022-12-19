### 解题思路
贪心算法求解：
思路：
从头到尾遍历数组，每到一个字符，查看这个字符出现的最后位置，取当前字符出现的最后位置以及前面遍历的这段字符中所有字符出现的最后位置的最大值，作为子串需要延展的最大结尾，如果这个最大值就是当前遍历的index值，则表示当前可以作为一个输出子串

先把原始数组从头到尾遍历，把每个字母出现的最后位置更新到表格中，一遍后续查找。


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #define SIZE 500
 #define CHR_NUM 26

 int max(int a, int b)
 {
     return a > b ? a : b;
 }

int* partitionLabels(char * S, int* returnSize){
    if (S == NULL) {
        return NULL;
    }

    int *retList = (int *)calloc(sizeof(int), SIZE);
    int retCnt = 0;
    int positionList[CHR_NUM] = {0};

    for (int i = 0; i < strlen(S); i++) {
        positionList[S[i] - 'a'] = i;
    }

    int maxLast = 0;
    int num = 0;

    for (int i = 0; i < strlen(S); i++) {
        maxLast = max(maxLast, positionList[S[i] - 'a']);
        num++;
        if (maxLast == i) {
            retList[retCnt] = num;
            retCnt++;
            num = 0;
        }
    }

    *returnSize = retCnt;
    return retList;
}
```