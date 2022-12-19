### 解题思路
题目中malloc在一个函数中分配，在另一个函数中free；
关键在于return的是 malloc的地址

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j;
int* list=(int *)malloc(3*sizeof(int));
for(i=0;i<numsSize-1;i++)
    for(j=i+1;j<numsSize;j++)
    if(target==(nums[i]+nums[j]))
        {
            list[0]=i;
            list[1]=j;
            * returnSize=2;
            return list;
        }

return NULL;
}
```