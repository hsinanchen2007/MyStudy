### 解题思路
拆圆圈
分别对
0 - n-2
1 - n-1
应用dp求最大值即可
状态转移方程为：
dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i])


### 代码

```java
class Solution {
    public int rob(int[] nums) {
        //两次dp思路
        //0 - n-2个数组
        //1 - n-1个数组
        
        //数组长度 n
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.max(nums[0], nums[1]);
        }

        //dp数组
        int[] dp1 = new int[n-1];
        dp1[0] = nums[0];
        dp1[1] = Math.max(nums[0], nums[1]);

        //0 - n-2
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = Math.max(dp1[i-1], dp1[i-2] + nums[i]);
        }

         //dp数组
        int[] dp2 = new int[n];
        dp2[1] = nums[1];
        dp2[2] = Math.max(nums[1], nums[2]);

        //1 - n-1
        for (int i = 3; i < n; i++) {
            dp2[i] = Math.max(dp2[i-1], dp2[i-2] + nums[i]);
        }

        return Math.max(dp1[n-2], dp2[n-1]);
    }
}
```