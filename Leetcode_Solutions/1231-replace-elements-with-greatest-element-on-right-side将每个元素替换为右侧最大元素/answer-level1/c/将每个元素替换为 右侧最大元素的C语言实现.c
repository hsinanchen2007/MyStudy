### 解题思路
该题解题较为简单，解决思路如下:
* 入参检查
* 分配并初始化数组，由于数组最后一位是-1，因此将数组初始化为-1
* 循环遍历数组，并获取每个数组元素后面最大值，并将该最大值放在result数组中


**Note:** 本题解法简单，但花费的时间和内存相对较大，并未找到好的优化方法。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int maxNumber(int *arr, int start, int end)
{
    int max = 0;
    if(!arr)
    {
        max = 0;
    }
    else
    {
        max = arr[start];
        for(int i=start; i<end;i++)
        {
            if(arr[i] >= max)
            {
                max = arr[i];
            }
        }
    }
    return max;
}

int* replaceElements(int* arr, int arrSize, int* returnSize)
{
    //入参检查
    if(!arr)
    {
        *returnSize = 0;
        return NULL;
    }

    //分配并初始化数组
    int *result = (int*)malloc(sizeof(int)*arrSize);
    memset(result, -1, sizeof(int)*arrSize);

    //循环遍历数组，获取最大值
    int max = 0;
    for(int i = 0; i<arrSize-1;i++)
    {
        max = maxNumber(arr,i+1,arrSize);
        result[i] = max;
    }
    *returnSize = arrSize;
    return result;
}
```