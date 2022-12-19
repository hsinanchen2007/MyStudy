### 解题思路
第一印象就是这个简单的循环了，不过这个执行时间有点太菜了哈哈哈哈啊哈

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i ,z ,j;
    z = target ;
    int *a = nums ;
    int  *b ;
    b = (int *)malloc(sizeof(int)*2);
    for(i=0 ; i<numsSize ; i++)
    {
        for( j=i+1 ; j<numsSize ;j++)
        {
            if((*(a+i) + *(a+j)) == z)
            {
                *b = i ;
                *(b+1) = j ;
                *returnSize = 2 ;
                return b ;
            }
        }
    }
    *returnSize = 0 ;
    return b ;

}
```