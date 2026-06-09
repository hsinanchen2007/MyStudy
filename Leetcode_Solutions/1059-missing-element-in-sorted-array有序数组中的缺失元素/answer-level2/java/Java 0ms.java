    public int missingElement(int[] nums, int k) {
        // 求出最大缺失数量
        int max = nums[nums.length - 1] - nums[0] - nums.length + 1;
        for (int i = 1; i < nums.length - 1; i++) {
            // 大于最大缺失数量，取数组最大值加第K缺失值，再减最大缺失值
            if (k > max) {
                return nums[nums.length - 1] + k - max;
            }
            int num = nums[i] - nums[0] - i;
            int num1 = nums[i + 1] - nums[0] - i - 1;
            // 当前k小于等于数组第i位数的缺失值时，取数组第0位加k（且只有i等于1时才可能会走此逻辑）
            if (k <= num) {
                return nums[0] + k;
            }
            if (k <= num1 && k > num) {
                return nums[i] + k - num;
            }
        }
        return 0;
    }