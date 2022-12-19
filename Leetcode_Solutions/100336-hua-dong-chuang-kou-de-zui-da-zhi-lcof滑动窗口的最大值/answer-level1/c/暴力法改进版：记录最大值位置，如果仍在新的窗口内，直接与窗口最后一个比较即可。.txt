### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(numsSize == 0){
        *returnSize = 0;
        return NULL;
    } 
    if(k == 1){
        *returnSize = numsSize;
        return nums;
    }
    *returnSize = numsSize - k + 1;
    int *res = (int *)malloc(sizeof(int) * (*returnSize));
    int max;
    int idx;
    for(int i = 0; i <= numsSize - k; i++){
        max = nums[i];

        if(i == 0 || idx == i - 1){
            // max out of the window
            idx = i;
            for(int j = 0; j < k; j++){
                if(max < nums[i + j]){
                   max = nums[i + j];
                   idx = i + j;
                }
            }
        }else{
            // max in the window
            if(nums[idx] < nums[i + k - 1]){
                max = nums[i + k - 1];
                idx = i + k - 1;
            }else{
                max = nums[idx];
            }
        }
        res[i] = max;
    }
    return res;
}
```