### 解题思路
先排序然后把最大差值找出来，最后再遍历比较。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(int* a,int* b)
{
    return *a>*b?1:0;
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr,arrSize,sizeof(int),cmp);
    int** num=(int**)malloc(sizeof(int*)*arrSize);
    *returnColumnSizes=(int*)malloc(sizeof(int)*arrSize);
    int* columnSizes=(int*)malloc(sizeof(int)*arrSize);
    int cnt=0;
    int temp=abs(arr[1]-arr[0]);
       for(int i=0;i<arrSize-1;i++)
       {
            if(abs(arr[i]-arr[i+1])<temp)
            {
                temp=abs(arr[i]-arr[i+1]);
            }
       }
    for(int i=0;i<arrSize-1;i++)
    {
        if(abs(arr[i]-arr[i+1])==temp)
        {
            int* a=(int*)malloc(sizeof(int)*2);
            a[0]=arr[i];
            a[1]=arr[i+1];
            num[cnt]=a;
            columnSizes[cnt++]=2;
        }
    }
    *returnSize=cnt;
    *returnColumnSizes=columnSizes;
    return num;
}
```