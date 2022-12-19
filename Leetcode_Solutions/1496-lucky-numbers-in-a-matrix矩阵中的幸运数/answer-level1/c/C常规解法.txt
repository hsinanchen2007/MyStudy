### 解题思路
常规解法，先找行最小，然后判断是否列最大

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_min(int arr[],int len)
{
    int min=arr[0],path=0;
    for(int i=1;i<len;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
            path=i;
        }
    }
    return path;
}

int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m=matrixSize,n=*matrixColSize;
    int *result=(int *)malloc(sizeof(int)*m);
    int count=0;
    for(int i=0;i<m;i++)
    {
        int path=get_min(matrix[i],n);
        int flag=0;
        for(int j=0;j<m;j++)
        {
            if(matrix[i][path]<matrix[j][path])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            result[count++]=matrix[i][path];
    }
    *returnSize=count;
    return result;
}
```