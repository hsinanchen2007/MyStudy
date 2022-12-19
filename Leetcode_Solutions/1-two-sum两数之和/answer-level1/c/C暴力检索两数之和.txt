### 解题思路
此处撰写解题思路
参考了一些人的代码，基本弄明白了leetcode的函数参数风格；
returnSize传入的是指针，是让子程序写入返回数组的元素个数，
这样调用者可以根据returnSize来查询改子程序返回的数组元素。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int *retnums =(int*)malloc(2*sizeof(int));
        memset(retnums, 0, sizeof(int) * 2);        
        *returnSize =0;
        for(int i=0;i<numsSize;i++)
        {
            for(int j=i+1;j<numsSize;j++)
            {
                if(target==nums[i]+nums[j])
                {
                    retnums[0]=i;
                    retnums[1]=j;
                    *returnSize=2;
                }
            }
        }
        return retnums;
}
```