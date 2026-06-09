```
public static int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {
            return new int[] {};
        }
        if (k == 1) {
            return nums;
        }
        int[] result = new int[nums.length - k + 1];
        // 首先检查出 前k个的最大值
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < k; i++) {
            max = Math.max(max, nums[i]);
        }
        result[0] = max;

        for (int i = k; i < nums.length; i++) {
            if (nums[i] >= max) {
                max = nums[i];
            } else {
                // 如果弹出了最大值重新选举
                if (nums[i - k] == max) {
                    int tmpmax = nums[i];
                    for (int j = i - k + 1; j <= i; j++) {
                        tmpmax = Math.max(nums[j],tmpmax);
                    }
                    max = tmpmax;
                }
            }
            result[i - k + 1] = max;
        }

        return result;
    }
```
