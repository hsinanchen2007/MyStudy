### 解题思路
最直接的想法，两两相加，判断和是否等于目标，有点类似于冒泡排序的遍历，只是把比较改成相加。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int * res = (int*)malloc(sizeof(int) * 2);

    for(i=0; i<=numsSize-1;i++) {
        for (j=i+1;j<=numsSize-1;j++) {
            if(nums[i] + nums[j] == target) {
                res[0]=i;
                res[1]=j;
                *returnSize=2;
                return res;
            }  
        }
    }
    return res;
}
```