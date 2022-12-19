### 解题思路
双层循环

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize,int *returnSize){
    int i,j=0;
    *returnSize=0;
    if(numsSize%2==0)
    {
        for(i=0;i<numsSize;i+=2)
        {
            (*returnSize)+=nums[i];
        }
        int* newl=(int *)malloc((*returnSize)*sizeof(int));
        int *p=newl;
        for(i=0;i<numsSize;i+=2)
        {
            for(j=0;j<nums[i];j++)
            {
                *p=nums[i+1];
                p++;
            }
        }
        return newl;
    }
else return NULL;
}


```