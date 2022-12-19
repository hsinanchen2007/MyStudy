### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *p=(int*)malloc(sizeof(int)*2);//w我觉得这个返回值是不严谨的，当没有l两个数相加是target时，
    int i,j;//我们是应该把*returnSize=0的。
            //h还有就是这个循环的执行效率不是太高。应该加一个标志变量和break
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                p[0]=i;
                p[1]=j;
            }
        }
    }
    *returnSize=2;
    return p;
    
}


```