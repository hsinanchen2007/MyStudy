### 解题思路
思路参考官方双指针

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int limit=(target-1)/2;
    if(limit<1)
    {
        *returnSize=0;
        return NULL;
    }
    int **result=(int **)malloc(sizeof(int *)*100);
    //for(int i=0;i<10;i++)
      //  result[i]=(int *)malloc(sizeof(int)*limit);      //这里不能提前开辟空间，否则超出限制内存
    int *col=(int *)malloc(sizeof(int)*limit);
    //*returnColumnSizes=(int *)malloc(sizeof(int)*limit);
    int count=0;
    for(int left=1,right=2;left<right && left<=limit;)
    {
        int sum=(left+right)*(right-left+1)/2;
        if(sum==target)
        {
            //*returnColumnSizes[count]=(right-left+1);
            result[count]=(int *)malloc(sizeof(int)*(right-left+1));
            col[count]=right-left+1;
            for(int i=left,k=0;i<=right;i++)
                result[count][k++]=i;
            count++;
            left++;
        }
        else if(sum<target)
            right++;
        else
            left++;
    }
    *returnColumnSizes=col;
    *returnSize=count;
    return result;
}
```