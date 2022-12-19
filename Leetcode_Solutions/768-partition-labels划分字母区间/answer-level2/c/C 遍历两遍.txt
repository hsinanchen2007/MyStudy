### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void init(char *S, int map[26])
{
    int i;
    int k;
    //int strLen = strlen(S);

    for (i = 0; i < strlen(S); ++i) {
        k = S[i] - 'a';//这个很好，利用差值，也按照字母表顺序排了
        if (i > map[k]) {
            map[k] = i;
        }
    }
}
/*
 * greedy algorithm with time complexity O(n^2)
 * optimize it to O(n) by finding the last pos  for each character at first
*/
int* partitionLabels(char * S, int* returnSize)
{   
    int lastPosOfCurChar;
    int start;
    int rangeR = 0;
    int *result = NULL;
    int  strLen;
    int  i;
    int map[26] = {0};//找到每个字母最后一个位置

    if (!S || !returnSize) {
        return NULL;
    }
    *returnSize = 0;
    strLen  = strlen(S);
    if (strLen == 0) {
        return NULL;
    }
    result = (int *)malloc(sizeof(int) * strLen);
    if (result == NULL) {
        return NULL;
    } 
    init(S, map);
    start = 0;
    lastPosOfCurChar = 0;
    for (i = 0; i < strLen; ++i) {
        lastPosOfCurChar = map[S[i] - 'a']; 
        if (lastPosOfCurChar == rangeR && i == rangeR) {
            result[(*returnSize)++] = rangeR - start + 1;
            rangeR = i + 1;
            start = rangeR;
        } else if (lastPosOfCurChar > rangeR){
            rangeR = lastPosOfCurChar;
        }
    }

    return result;
 }
```