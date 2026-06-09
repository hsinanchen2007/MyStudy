    public int massage(int[] nums) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }

给出一组数据：1、2、3、2、1、5、7、6，求不相邻的数字的最大和

令$F_i$ 表示有$i$个数时选择的最大和：

${F_i = max\{ c_i+f_{i-2};f_{i-1} \}, i \geqslant 2}$

$F_0=0 \quad f_1=c_1 = 1$