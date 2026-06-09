    // 基于桶的思想，但是没用桶排序：
	// n个数要有n + 1 个桶，由于鸽巢原理，一个萝卜一个坑，必定最少有一个桶为空
	// 设置空桶的目的只有一个，那就是桶内相邻的数的gap一定不是答案，答案一定是两桶之间的min和max的gap。
	// 答案不一定来自空桶两侧，也可能来自相邻桶
    class Solution {
        public int maximumGap(int[] nums) {
            if(nums == null || nums.length < 2) {
                return 0;
            }
            int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            for(int i = 0;i < nums.length;i++) {
                min = Math.min(min, nums[i]);
                max = Math.max(max, nums[i]);
            }
            if(min == max) {
                return 0;
            }
            int len = nums.length;
            // 用三组数来表示一个桶，是否有值，桶内的最大值，桶内的最小值
            boolean[] hasNum = new boolean[len + 1];
            int[] maxs = new int[len + 1];
            int[] mins = new int[len + 1];
            for(int i = 0;i < len;i++) {
                // num[i]为min时表示第0号桶，num[i]为max时表示第len号桶，正好是len + 1个桶，必有空桶
                // 乘法可能会溢出，所以用的long，试了试先除后乘，len放在最后，结果求出桶的index不对
                int index = (int)((nums[i] - min) * (long)len / (max - min));
                maxs[index] = hasNum[index] ? Math.max(maxs[index], nums[i]) : nums[i];
                mins[index] = hasNum[index] ? Math.min(mins[index], nums[i]) : nums[i];
                hasNum[index] = true;
            }
            int res = 0;
            int lastmax = maxs[0];
            // 遍历len + 1个桶，计算gap
            for(int i = 1;i < len + 1;i++) {
                if(hasNum[i]) {
                    res = Math.max(res, mins[i] - lastmax);
                    lastmax = maxs[i];
                }
            }
            return res;
        }
    }