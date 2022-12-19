### 解题思路
1. 把二维输入存入一维数组中；
2. 把一维数组排序；qsort搞定
3. 按要求输出第k-1个元素

### 代码

```c

/* 升序排列 */
int Cmpfunc1 (const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        return 0;
    }

    int arraySize = matrixSize * matrixSize;
    int* tempArray = (int *)malloc(arraySize * sizeof(int)); 
    memset(tempArray, 0, arraySize * sizeof(int));

    // 遍历二维输入，存入数组中
    int index = 0;
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            tempArray[index] = matrix[i][j];
            index++;
        }
    }

    // 数组排序
    qsort(tempArray, arraySize, sizeof(int), Cmpfunc1);

    return tempArray[k - 1];
}
```