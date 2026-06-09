```
    class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            if (nums.length * k == 0) return new int[0];
            if (k == 1) {
                return nums;
            }
            int[] maxes = new int[nums.length - k + 1];
            int max = maxnum(nums, 0, k);
            maxes[0] = max;
            for (int i = k; i < nums.length; i++) {
                //如果下一个大于等于max，那么更新max
                if (nums[i] >= max) {
                    max = nums[i];
                } else {
                    //如果下一个小于max，且max已经离开滑动窗口，那么重新搜索新窗口中的最大值
                    if (max == nums[i - k]) {
                        max = maxnum(nums, i - k + 1, k);
                    }
                //在上述两种情况之外，max没有发生改变，所以不变
                }
                maxes[i - k + 1] = max;
            }
            return maxes;
        }

        public int maxnum(int[] nums, int start, int k) {
            int max = nums[start];
            for (int i = start; i < start + k; i++) {
                if (nums[i] > max) {
                    max = nums[i];
                }
            }
            return max;
        }
    }
```

