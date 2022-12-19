题目：选取一组数的前小数
qsort（起始位置，大小，每一个位置大小，比较两数的函数）
从小到大

奥里给！ 干就完了

### 代码

```c
int IntegerCmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    qsort(arr,arrSize,sizeof(int),IntegerCmp);

    *returnSize = k;
    return arr;
}
```