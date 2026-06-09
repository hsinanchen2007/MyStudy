```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ans = (int*)malloc(2 * sizeof(int));
    int p1 = 0, p2 = numsSize - 1;
    while(1){
        if(nums[p1] + nums[p2] == target){
            break;
        }
        else if(nums[p1] + nums[p2] > target){
            p2--;
        }
        else{
            p1++;
        }
    }
    ans[0] = nums[p1];
    ans[1] = nums[p2];
    *returnSize = 2;
    return ans;
}
```
