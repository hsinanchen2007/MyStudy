// 斐波那契 时间复杂度：O(n) 空间复杂度：O(1)
    // 状态转换方程 f(n) = f(n-1) + f(n-2)
    public int climbStairsFib(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int first_value = 1;
        int sec_value = 2;
        for (int i = 3; i <= n; i++)
        {
            int recentValue = first_value + sec_value;
            first_value = sec_value;
            sec_value = recentValue;
        }
        return sec_value;

    }

    // 动态规划 时间复杂度：O(n) 空间复杂度：O(n)
    // 状态转换方程 f(n) = f(n-1) + f(n-2)
    public int climbStairsDP(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int dp[] = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {

            dp[i] = dp[i - 1] + dp[i - 2];
            System.out.println(i + ":" + dp[i]);
        }
        return dp[n];
    }

    // 递归
    public int climbStairsRecur(int n, int[] memo)
    {

        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        if (memo[n] > 0)
        {
            return memo[n];
        }

        memo[n] = climbStairsRecur(n - 1, memo) + climbStairsRecur(n - 2, memo);
        return memo[n];

    }

    // 优化的递归 注意递归本身不能太多层，stack over
    public int climbStairs(int n)
    {
        int[] memo = new int[n + 1];
        return climbStairsRecur(n, memo);

    }

    // 最大子序和
    // 动态规划
    public int maxSubArray(int[] nums)
    {

        // 初始化开始数据
        int max = nums[0];

        // 初始化开始数据
        int dp = nums[0];

        for (int i = 1; i < nums.length; i++)
        {
            // dp
            dp = Math.max(dp + nums[i], nums[i]);
            max = Math.max(max, dp);
        }
        return max;

    }

    // 暴力解法
    public int maxSubArrayExhaustive(int[] nums)
    {
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++)
        {
            int sum = 0;
            for (int j = i; j < nums.length; j++)
            {
                sum = sum + nums[j];
                result = Math.max(result, sum);
            }
        }
        return result;
    }

    // 包含mid 查找最大连续和
    public int maxCorssMidSum(int[] nums, int left, int right, int mid)
    {
        int leftMax = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            if (sum > leftMax)
            {
                leftMax = sum;
            }
        }

        int rightMax = Integer.MIN_VALUE;

        sum = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            if (sum > rightMax)
            {
                rightMax = sum;
            }
        }
        System.out.println("leftMax:" + leftMax + " rightMax:" + rightMax);

        return leftMax + rightMax;

    }

    // 左右查找
    public int maxSubArraySum(int[] nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }

        int mid = (left + right) / 2;
        System.out.println("begin to left.." + "[" + left + " " + mid + " "
                + right + "]");
        int leftMax = maxSubArraySum(nums, left, mid);

        System.out.println("begin to right.." + "[" + left + " " + mid + " "
                + right + "]");
        int rightMax = maxSubArraySum(nums, mid + 1, right);

        System.out.println("begin to merge.." + "[" + left + " " + mid + " "
                + right + "]");
        int crossMax = maxCorssMidSum(nums, left, right, mid);

        int value = Math.max(crossMax, Math.max(leftMax, rightMax));

        System.out.println("[" + left + " " + mid + " " + right + "]"
                + " leftMax:" + leftMax + " crossMax:" + crossMax
                + " rightMax:" + rightMax + " value:" + value);
        return value;
    }

    // 分治算法
    public int maxSubArrayDivid(int[] nums)
    {

        int length = nums.length;
        return maxSubArraySum(nums, 0, length - 1);

    }