## 解析
当记录到第n个数的时候 ，用一个变量sum记录连续序列的和。那么如果sum<=0的话。
    表明sum+nums[n]将会小于nums[n]。因此。如果我么要找最大的序列和，前面的sum对我们是没有帮助的。
    我们应该将其舍弃。即sum = nums[n]。如果sum > 0的话。sum+nums[n]将会大于nums[n]。
    因此sum = sum+nums[n]。
    用res表示最大子序列和。每次更新完sum的值，看看sum是否比res大。如果比res大，更新res为num的值。
## 代码
```java
public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (sum <= 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            res = res > sum ? res : sum;
        }

        return res;
    }
```