### 解题思路
C语言暴力解题

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
int i=0,j=0;
int *a = (int *)malloc(sizeof(int) * 2);
for(i;i<numsSize-1;i++){
    for(j=i+1;j<numsSize;j++){
        if(target == nums[i]+nums[j]){
            a[0]=i;
            a[1]=j;
            *returnSize=2;
            return a;
        }
    }
}
*returnSize=0;
return a;
}
```