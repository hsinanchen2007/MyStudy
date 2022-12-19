思路：同精选题解
一次遍历，维护最大值，当前最大值，当前最小值
遇到负数则交换当前最大值和最小值
```
int maxProduct(int* nums, int numsSize){
    int max = INT_MIN;
    int imax = 1;
    int imin = 1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < 0){
            imax = imax ^ imin;
            imin = imax ^ imin;
            imax = imax ^ imin;
        }
        imax = fmax(imax * nums[i], nums[i]);
        imin = fmin(imin * nums[i], nums[i]);
        max = fmax(max, imax);
    }
    return max;
}
```
