![image.png](https://pic.leetcode-cn.com/7a456deb16efa8874f340ac00839da870efe6f3148b5378f22249ea94867bd9d-image.png)
```
/*
 * 输入people是长度为peopleSize的数组指针的数组，其中每个元素（也是一个数组）的长度组成peopleColSize数组作为另一输入，peopleColSize数组的长度也为peopleSize
 * 返回为 *returnSize大小的数组指针的数组，其中每个元素（也是一个数组）的长度组成*returnColumnSizes数组返回，*returnColumnSizes数组的长度也为 *returnSize。
 * 注意：返回的数组以及其数组元素、和 *returnColumnSizes数组都必须在给定的函数内进行内存分配，由框架代码进行内存释放。
 */

#define COLNUM 2

int Cmp(const void *a, const void *b)
{
    if ((*(int **)a)[1] != (*(int **)b)[1]) {
        return (*(int **)a)[1] - (*(int **)b)[1];
    } else {
        return (*(int **)b)[0] - (*(int **)a)[0];
    }
}

void RebuildRetrunStr(int **returnStr, int *returnStrNum, int *inputStr)
{
    int i;
    int j;
    int index = 0;
    
    if (*returnStrNum == 0) {
        returnStr[*returnStrNum][0] = inputStr[0];
        returnStr[*returnStrNum][1] = inputStr[1];
        (*returnStrNum)++;
        goto _END_;
    }
    
    for (i = 0; i < *returnStrNum; i++) {
        if (returnStr[i][0] >= inputStr[0]) {
            index++;
        }

        if (index > inputStr[1]) {
            for (j = *returnStrNum - 1; j >= i; j--) {
                returnStr[j + 1][0] = returnStr[j][0];
                returnStr[j + 1][1] = returnStr[j][1];
            }
            returnStr[i][0] = inputStr[0];
            returnStr[i][1] = inputStr[1];
            (*returnStrNum)++;
            goto _END_;
        }
    }
    
    (*returnStrNum)++;
    returnStr[*returnStrNum - 1][0] = inputStr[0];
    returnStr[*returnStrNum - 1][1] = inputStr[1];
    
    _END_:
    return;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    if ((people == NULL) || (peopleSize == 0) || (peopleColSize == NULL) || (*peopleColSize == 0)) {
        *returnSize = 0;
        (*returnColumnSizes) = (int *)malloc(1 * sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return NULL;
    }
    
    int i;
    int returnStrNum = 0;
    int **returnStr = (int **)malloc(peopleSize * sizeof(int *));
    
    for (i = 0; i < peopleSize; i++) {
        returnStr[i] = (int *)malloc(COLNUM * sizeof(int));
        memset(returnStr[i], 0, COLNUM * sizeof(int));
    }
    
    *returnSize = peopleSize;
    (*returnColumnSizes) = (int *)malloc(peopleSize * sizeof(int));
    qsort(people, peopleSize, sizeof(people[0]), Cmp);

    for (i = 0; i < peopleSize; i++) {
        RebuildRetrunStr(returnStr, &returnStrNum, people[i]);
        (*returnColumnSizes)[i] = COLNUM;
    }
    
    return returnStr;
}



```
