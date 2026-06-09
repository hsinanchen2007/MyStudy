#### 虽然我是个菜鸡
#### 但是此题做不出来以后不配去会所按摩！！！
#### 动态规划，本菜对动态规划掌握的还不是很好，见谅..
### 代码

```java
class Solution {
    public int massage(int[] nums) {
        
        //判断一下
        if (nums.length == 0)
            return 0;

        if (nums.length<2)
            return nums[0];

        if (nums.length<3)
            return Math.max(nums[0],nums[1]);


        //如果数组超过了3，就动态规划，
        //前三个元素和原数组一样，其他初始值赋值为-1
        int[] dp = new int[nums.length];

        Arrays.fill(dp,-1);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];


        int max = 0;

        //当前接单代表前一单必定不能接，所以判断一下接下当前单之后前两单和前三单那个时间比较长
        //去最长的作为当前最有解
        for (int i = 3; i < nums.length; i++) {
            dp[i] = Math.max(dp[i-2]+nums[i],dp[i-3]+nums[i]);
        }

        for (int value : dp) {
            max = Math.max(value, max);
        }

        return max;
    }
}
```