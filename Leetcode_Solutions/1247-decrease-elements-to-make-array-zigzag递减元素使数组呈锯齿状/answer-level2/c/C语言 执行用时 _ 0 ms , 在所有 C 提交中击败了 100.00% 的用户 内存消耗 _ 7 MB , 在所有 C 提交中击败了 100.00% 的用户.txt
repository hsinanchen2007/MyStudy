```
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int movesToMakeZigzag(int* nums, int numsSize){
    int ans1 = 0;
    int ans2 = 0;
    //*       *       *       *
    //  *   *   *   *   *   *
    //    *       *       * 
    for(int i = 1;i < numsSize;i += 2) {
        int raise = 0;
        if(nums[i] >= nums[i-1]) {
            raise = abs(nums[i] - nums[i-1]) + 1;
        }
        if(i + 1 < numsSize && nums[i] >= nums[i+1]) {
            raise = max(raise,abs(nums[i]-nums[i+1])+1);//减少到刚好比相邻的偶数位置元素小
        }
        ans1 += raise;
    }
    //     *       *       *       *
    //   *   *   *   *   *   *   *   *
    // *       *       *       *       *
    for(int i = 0;i < numsSize;i += 2) {
        int raise = 0;
        if(i > 0 && nums[i] >= nums[i-1]) {
            raise = abs(nums[i]-nums[i-1])+1;
        }
        if((i+1) < numsSize && nums[i] >= nums[i+1]) {
            raise = max(raise,abs(nums[i]-nums[i+1])+1);////减少到刚好比相邻的奇数位置元素小
        }
        ans2 += raise;
    }
    return min(ans1,ans2);
}
```
