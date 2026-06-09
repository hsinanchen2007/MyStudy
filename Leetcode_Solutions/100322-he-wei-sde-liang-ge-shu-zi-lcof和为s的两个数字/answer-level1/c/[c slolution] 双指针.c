### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if(numsSize <= 0){
        return nums;
    }
    int* res = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    int left = 0 , right = numsSize - 1 , sum = 0;
    while(left < right){
        sum = nums[left] + nums[right];
        if( sum == target){
            res[0] = nums[left];
            res[1] = nums[right];
            break;
        }
        if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    return res;
}
```