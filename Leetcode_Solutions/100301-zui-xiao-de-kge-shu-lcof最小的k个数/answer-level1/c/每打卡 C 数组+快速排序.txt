### 解题思路
快速排序后将前k个输出

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;    
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize)
{
    int *result=calloc(k,sizeof(int));
    *returnSize = k;
    
    qsort(arr,arrSize,sizeof(int),comp) ;
    for(int i=0; i<k; i++)
    {
        result[i]= arr[i];
    }

    return result;
}

```