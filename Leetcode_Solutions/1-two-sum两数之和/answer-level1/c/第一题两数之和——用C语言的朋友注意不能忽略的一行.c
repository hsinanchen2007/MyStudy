### 解题思路
方法是暴力搜索，两个for嵌套。
代码中需要给returnSize指向的变量赋值，即*returnSize=2，否则代码会报溢出错误

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int* returned_array = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for(i=0;i<=numsSize-2;i++){
        for(j=i+1;j<=numsSize-1;j++){
            if(nums[i]+nums[j]==target){
                returned_array[0] = i;
                returned_array[1] = j;
                return returned_array;
                // break;
            }
        }
    }
    return returned_array;
}
```