直接递归（很慢 ，一般情况下不行，这题可以直接过）
~~~
    public boolean PredictTheWinner(int[] nums) {
        return getScore(nums, 0, nums.length - 1) >= 0;
    }
    private int getScore(int[] nums, int left, int right) {
        if (left == right) {
            //只剩一个时候 第一个人肯定选了
            return nums[left];
        }
        return Math.max(nums[left] - getScore(nums, left + 1, right), nums[right] - getScore(nums, left, right - 1) );
    }
~~~
将结果放到memo中（执行用时：0 ms）
~~~
    public boolean PredictTheWinner(int[] nums) {
        if (nums.length <= 1) {
            return true;
        }
        int n = nums.length;
        return getScore(nums, 0, nums.length - 1, new int[n][n]) >= 0;
    }

    private int getScore(int[] nums, int l, int r, int[][] memo) {
        if (l == r) {
            memo[l][r] = nums[l];
            return nums[l];
        }
        if (memo[l][r] != 0) {
            return memo[l][r];
        }
        int max = Math.max(nums[l] - getScore(nums, l + 1, r, memo), nums[r] - getScore(nums, l, r - 1, memo));
        memo[l][r] = max;
        return max;
    }
~~~