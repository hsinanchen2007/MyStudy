## 二维数组作为输入和输出参数
```int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)```
### 输入参数
输入参数interval是一个二维数组，intervalsSize是这个二维数组的第一维大小，intervalsColSize是第一维每个元素指向的数组的大小。
### 输出参数
- 输出参数1：return值，需要malloc二维数组
- 输出参数2：*returnSize，针对函数调用者，**这就是一个int类型**，直接赋值二维数组的长度，即*returnSize = len;
- 输出参数3：\*\*returnColumnSizes，针对调用者来说，是一个int*型的变量，也就是一个数组，这个需要malloc一个一维数组，数组内容是参数1的二维数组的每一个元素指向数组的大小。

```
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **returnVal = (int **)malloc(sizeof(int *) * validNum);
    for (int i = 0; i < validNum; ++i) {
        returnVal[i] = (int *)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < intervalsSize; ++i) {
        returnVal[i][0] = intervals[i][0];
        returnVal[i][1] = intervals[i][1];

    }
    *returnSize = validNum;
    *returnColumnSizes = (int *)malloc(sizeof(int) * validNum);
    for (int i = 0; i < validNum; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return returnVal;
}
```

## CMP函数
数组定义原型：int**，可以理解为这是一个一维数组，每个元素是一个指针，每个指针指向一个数组。
那么传入cmp的void指针是（数组元素）的地址，也就是（指针）的地址，那么目前数组元素是int*类型的，int *类型的指针就是int**，所以
在cmp函数内对void指针强转就是int**类型的，获取数组元素为int*类型。
```
int Cmp(const void *a, const void *b)
{
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;

    if (p1[0] != p2[0]) {
        return p1[0] - p2[0];
    }

    return p1[1] - p2[1];
}
```