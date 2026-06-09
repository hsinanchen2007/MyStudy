### 解题思路
就单纯的暴力呗

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int Max(int a,int b)
 {
     return a>b? a:b;
 }
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
     if((nums == NULL) || (numsSize == 0) || (k == 0)) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize=numsSize-k+1;
    int * ret=(int *)malloc(sizeof(int)*(*returnSize));
    int i=0,j=0,max=0;
    int MAX_INT = ((unsigned)(-1))>>1;
    int MIN_INT = ~MAX_INT;

    for(i=0;i<(*returnSize);i++)
    {
         max=MIN_INT;
        for(j=i;j<i+k;j++)
        {    
            max=Max(max,nums[j]);
        }
        ret[i]=max;
    }
    return ret;

}
```