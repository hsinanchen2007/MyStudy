### 解题思路

c才是世界上最好的语言！只用c解题

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int left = 0 , right = numsSize - 1 ;
    *returnSize = 2;
    int* ret = (int*)malloc(sizeof(int)*2);
    ret[0] = -1 ;
    ret[1] = -1 ;
    while(left <= right){
        int mid = (left + right) / 2 ;
        if(nums[mid] < target){
            left = mid + 1;
        }
        if(nums[mid] > target){
            right = mid - 1;
        }
        if(nums[mid] == target){
            right = mid;
            left = mid;
            while(right < numsSize && right >= 0 && nums[right] == target ){
                right++;
            }
            while(left < numsSize && left >= 0 && nums[left] == target ){
                left--;
            }
            ret[0] = left + 1;
            ret[1] = right - 1;
            break;
        } 
    }
    return ret;

}
```