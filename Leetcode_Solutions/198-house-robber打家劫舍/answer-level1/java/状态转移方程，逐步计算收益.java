```
if (nums == null || nums.length <= 0) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        } else if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }

        // 动态规划；
        int[] award = new int[nums.length];
        award[0] = nums[0];
        award[1] = nums[1];
        award[2] = Math.max(award[0] + nums[2], award[1]);
        for (int i = 3; i < nums.length; i++) {
            award[i] = Math.max(award[i - 1], Math.max(award[i - 2], award[i - 3]) + nums[i]);
        }
        return award[nums.length - 1];
```