使用官方题解思路，优化后的代码，更简洁

    public int firstMissingPositive(int[] nums) {
      int n = nums.length;
        int[] tmps = new int[n];

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) {
                tmps[nums[i] - 1]++;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (tmps[i] == 0) {
                result = i + 1;
                break;
            }
        }

        if (result == 0) {
            return n + 1;
        }

        return result;
    }