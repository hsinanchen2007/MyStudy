### 解题思路
左侧得到i元素前的累乘，右侧得到i元素后的累乘

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    *returnSize=aSize;
    int *result=(int *)malloc(sizeof(int)*aSize);
   // for(int i=0;i<aSize;i++)
     //   result[i]=1;
    int left=1,right=1;
    for(int i=0;i<aSize;i++)
    {
        result[i]=left;
        left*=a[i];
    }
    for(int i=aSize-1;i>=0;i--)
    {
        result[i]*=right;
        right*=a[i];
    }
    return result;
}


```