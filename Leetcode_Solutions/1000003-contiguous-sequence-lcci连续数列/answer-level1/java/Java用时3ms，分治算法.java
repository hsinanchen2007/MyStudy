思路来自博客 https://blog.csdn.net/abnerwang2014/article/details/36027747
大概地说一下，答案可能在三个地方出现，取最大值就行
1. 数组左边
2. 数组右边
3. 横跨数组

那么为了求数组的答案，先求数组左边的答案leftSum；再求数组右边的答案rightSum;
对于横跨中间的，我们知道必须要取得中间位置-1和中间位置才算横跨。
为什么是中间位置-1和中间位置呢？按理解来说，需要取得将数组一分为2后，左边数组的最后一个和右边数组的第一个才算横跨。
由于在代码中，使用的区间是左闭右开，所以左边数组的最后一位为中间位置-1，右边数组的第一位是中间位置。

```
class Solution {
    int[] nums;
    public int maxSubArray(int[] nums) {
        this.nums = nums;
        return solve(0, nums.length);
    }
    private int solve(int l, int r){
        if(l == r - 1){
            return nums[l];
        }
        int leftSum, rightSum, middleSum;
        int middle = (l + r) >> 1;
        leftSum = solve(l, middle);
        rightSum = solve(middle, r);

        int middleftSum = nums[middle - 1], maxMiddleLeftSum = nums[middle - 1];
        for(int i = middle - 2; i >= l; i --){
            middleftSum += nums[i];
            if(middleftSum > maxMiddleLeftSum){
                maxMiddleLeftSum = middleftSum;
            }
        }

        int middleRightSum = nums[middle], maxMiddleRightSum = nums[middle];
        for(int i = middle + 1; i < r; i ++){
            middleRightSum += nums[i];
            if(middleRightSum > maxMiddleRightSum){
                maxMiddleRightSum = middleRightSum;
            }
        }

        return Math.max(leftSum, Math.max(rightSum, maxMiddleLeftSum + maxMiddleRightSum));
    }
}
```
