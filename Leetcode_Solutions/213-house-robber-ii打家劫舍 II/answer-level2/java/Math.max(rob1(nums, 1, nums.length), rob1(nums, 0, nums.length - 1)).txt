将原来的题改改
```
public int rob(int[] nums) {
        if(nums.length<3)
            return getInteger(nums);
        return Math.max(rob1(nums, 1, nums.length), rob1(nums, 0, nums.length - 1));
    }

    public int rob1(int[] nums1, int start, int end) {
        int[] nums = new int[end - start];
        for (int i = start; i < end; i++)
            nums[i-start] = nums1[i];
        if(nums.length<3)
            return getInteger(nums);


        int[] dp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            dp[i] = Math.max(i - 2 < 0 ? 0 : dp[i - 2], i - 3 < 0 ? 0 : dp[i - 3]) + nums[i];
        }

        return dp[dp.length - 1] > dp[dp.length - 2] ? dp[dp.length - 1] : dp[dp.length - 2];
    }

    private Integer getInteger(int[] nums) {
        if (nums.length == 0)
            return 0;
        else if (nums.length==1)
            return nums[0];
        else  if (nums.length == 2)
            return Math.max(nums[0], nums[1]);
        else
            return null;
    }
```