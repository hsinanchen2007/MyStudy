### 解题思路
此处撰写解题思路
c语言挺快的，就是有点不理解为什么要在函数中还要添加一个参数，否则报错
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target,int *c){
int i,j;
int *b=(int*)malloc(sizeof(int)*2);
for(i=0;i<numsSize;i++)
{
    for(j=0;j<numsSize;j++)
    {
        if(nums[i]+nums[j]==target)
        {
            if(i<j)
            {
                b[0]=i;
                b[1]=j;
                *c=2;
                return b;
            }
        }
    }
}
return b;
}
```