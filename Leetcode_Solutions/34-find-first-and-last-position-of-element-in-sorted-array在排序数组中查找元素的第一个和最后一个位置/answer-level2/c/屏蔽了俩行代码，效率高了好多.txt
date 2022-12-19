### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *p = (int *)malloc(sizeof(int)*2);
    p[0]=-1;
    p[1]=-1;
    //if(nums == NULL || numsSize <= 0)
   //     return p;

   // if(target < nums[0] || target > nums[numsSize-1])
   //     return p;
    int i;
    
    for(i=0;i<numsSize;i++)
    {
        if(nums[i] == target)
        {
            p[0]=i;
            p[1]=i;
            while(i<numsSize && nums[i] == target)
            {
                i++;
            }
            p[1]=i-1;
            break;
        }
    }
    return p;
}
```