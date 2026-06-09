### 解题思路
此处撰写解题思路
*returnSize 这个东西是真坑啊
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   // static int ans[2]={0};
   *returnSize=2;
    int* ans=(int *)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
   return ans; 
}
```