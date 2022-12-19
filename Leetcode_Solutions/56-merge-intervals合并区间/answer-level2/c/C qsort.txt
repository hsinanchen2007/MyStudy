### 解题思路
先用qosrt排序数组，之后一个接一个合并即可
![捕获.PNG](https://pic.leetcode-cn.com/15ef566b91c6f932f215eba1a32aeea6cd50be2c92fe24e6dda15e0b5703b173-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(void *a, void *b)
{
    int *arr1=*(int **)a;
    int *arr2=*(int **)b;
    if(arr1[0]==arr2[0])
        return arr1[1]-arr2[1];
    return arr1[0]-arr2[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if(intervalsSize<1)
        return NULL;
    qsort(intervals,intervalsSize,sizeof(int *),compare);
    int **result=(int **)malloc(sizeof(int *)*intervalsSize);
    int flag=0,start=-1,end=-1;
    for(int i=0;i<intervalsSize;i++)
    {
        if(i+1<intervalsSize && intervals[i+1][0]>=intervals[i][0] && intervals[i+1][0]<=intervals[i][1])
        {
            intervals[i+1][0]=intervals[i][0];
            intervals[i+1][1]=intervals[i][1]>intervals[i+1][1]?intervals[i][1]:intervals[i+1][1];   //防止区间包含
        }
        else
        {
            result[*returnSize]=(int *)malloc(sizeof(int)*2);
            result[*returnSize][0]=intervals[i][0];
            result[*returnSize][1]=intervals[i][1];
            (*returnSize)++;
        }
    }
    *returnColumnSizes=intervalsColSize;
    return result;
}
```