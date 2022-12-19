```
//解法一：直接二维数组，动态规划。思考如下：对于前i个数，需要保存i个数的最值，但是在考虑i+1的状态时，需要考虑是否计算第i个值，因而采用二维
//数组，dp[i][0]表示前i个数在不取i情况下的最值，dp[i][1]表示在前i个数取i的情况下的最值。
 public static int Massage(int[] nums)
        {
            
            if (nums.Length == 0) return 0;
            int[][] dp = new int[nums.Length + 1][];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i] = new int[2];
            }
            dp[0][0] = 0;
            dp[0][1] = 0;
            dp[1][0] = 0;
            dp[1][1] = nums[0];
            for (int i = 0; i < dp.Length; i++)
            {
                dp[i][0] = Math.Max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = Math.Max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
            }
            int res = Math.Max(dp[nums.Length][0], dp[nums.Length][1]);
            return res;
        }
//解法二：既然每次计算的时候，只需要考虑前一个状态（i-1时）有没有i的情况，而没有用到之前（i-2、i-3等），因而我们没有必要申请数组，直接用
//两个变量保存当前状态下，也就是在i状态下，根据第i个元素是否参加运算最值情况分类，然后每次比较完再交换顺序。
            if (nums.Length == 0) return 0;
            int dp0 = 0;
            int dp1 = nums[0];
            for (int i = 1; i < nums.Length; i++)
            {
                int dpt0 = Math.Max(dp0, dp1);//dpt0表示不用nums[i]参与计算
                int dpt1 = Math.Max(dp0 + nums[i], dp1);//dpt1表示用nums[i]参与计算

                dp0 = dpt0;
                dp1 = dpt1;
            }
            return Math.Max(dp0, dp1);
//解法三：经过前两种方法的探究，我们已经知道了动态规划的转移方程是：dp[i] = Math.Max(dp[i-1],dp[i-2]+nums[i-1]),那么可以直接用该方式求解
            if (nums.Length == 0) return 0;
            if (nums.Length == 1) return nums[0];
            if (nums.Length == 2) return Math.Max(nums[0], nums[1]);
            int[] dp = new int[nums.Length + 1];
            dp[0] = 0;
            dp[1] = nums[0];
            dp[2] = Math.Max(nums[0], nums[1]);
            for (int i = 3; i <= nums.Length; i++)
            {
                dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            }
            return dp[nums.Length];
```
