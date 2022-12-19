### 解题思路
此处撰写解题思路

### 代码

```c


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *) malloc(sizeof(int)*2);
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    int i;
    for ( i = 0; i < numsSize; i++ ) {
        if ( nums[i] == target ) {
            ans[0] = i;
            break;
        }
    }
    for ( i = numsSize-1; i >= 0; i-- ) {
        if ( nums[i] == target ) {
            ans[1] = i;
            break;
        }
    }
    return ans;
}


```