### 解题思路
1.构造一个结束条件
2.找到每个解空间树节点的特征，也就是说要明确解空间树节点是什么，本题中的节点是结果字符串的一个状态
3.回溯
本题由于是不重复的字符组成的字符串，所以比较简单，思路是构造一个字符组数，将S中的字符挨个拆下来，
用"qwe"为例，构造一个长度为4的字符数组，最后一位置'\0'，然后依次从S中拆字符，装入其中的每个位置，
每个位置都可以看做一个回溯点

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void fillArr(char* S, char **retArr, char *tempStr, int *count, int strSize)
{
    int i;
    // 结束条件：S中的字符耗尽即为结束
    if (strlen(S) == 0) {
        retArr[*count] = (char *)malloc(sizeof(char) * strSize);
        strcpy(retArr[(*count)++], tempStr);
        return;
    }
    // 从剩余的字符串中摘下一个，作为待插入字符
    char word = S[0];
    for (i = 0; i < strSize - 1; i++) {
        // 遍历 tempStr 插入一个空位置
        if (tempStr[i] == 0) {
            tempStr[i] = word;
            // 继续插字符
            fillArr(S + 1, retArr, tempStr, count, strSize);
            // 该位置置空，让本次循环中的这个字符去填充别的位置，开始回溯
            tempStr[i] = 0;
        }
    }
    return;
}
char** permutation(char* S, int* returnSize){
    int strSize = strlen(S) + 1;
    // 要留下足够的空间
    char **retArr = (char **)malloc(sizeof(char *) * 100000);
    char *tempStr = (char *)malloc(sizeof(char) * strSize);
    // 将 tempStr 每个位置都置 0，代表空的位置
    memset(tempStr, 0, strSize);
    // 最后一位置 \0
    tempStr[strSize - 1] = '\0';
    int count = 0;

    fillArr(S, retArr, tempStr, &count, strSize);
    * returnSize = count;
    return retArr;
}
```