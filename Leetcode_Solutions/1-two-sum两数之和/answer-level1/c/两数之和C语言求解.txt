### 解题思路
此处撰写解题思路
比较粗糙的解法：遍历所有情况，直到找到符合条件的情况，然后用动态数组记录下来，返回结果！
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i,j;
int *p = NULL;
p = (int *)malloc(sizeof(int)*2);
for (i=0;i<numsSize;i++){
    for (j=i+1;j<numsSize;j++)
    {
        if (nums[i]+nums[j]==target){
            p[0] = i;
            p[1] = j;
            *returnSize = 2;
            return p;
        }
    }
}
return 0;
}
```