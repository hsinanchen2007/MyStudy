思路：
保存两个递增的数，遍历找下一个数，
如果比第二个数大就返回成功，
如果比最小数小，则更新最小的数，
如果比最小数大，比第二个数小，则更新第二个数
```
bool increasingTriplet(int* nums, int numsSize){
    if(numsSize < 3){
        return false;
    }
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(int i = 0; i < numsSize; i ++){
        if(nums[i] > min2){
            return true;
        }
        if(nums[i] < min1){
            min1 = nums[i];
        }
        if(min1 < nums[i] && nums[i] < min2){
            min2 = nums[i];
        }
    }
    return false;
}
```
