### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    if(numsSize < 0){
        return nums;
    }
    *returnSize = numsSize;
    int left  = 0 , right = numsSize -1 ;
    while(left < right){
        while(left < right && ((nums[left] & 1) == 1)){
            left++;
        }
        while(right > left && ((nums[right] & 1) == 0)){
            right--;
        }
        int tmp = nums[right];
        nums[right] = nums[left];
        nums[left] = tmp;
        left++;
        right--;
    }

    return nums;
}
```