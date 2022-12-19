    
    class Solution {
        public int maxProduct(int[] nums) {
            int[] max = new int[nums.length];   // 以该数结尾乘积的最大值
            int[] min = new int[nums.length];   // 以该数结尾乘积的最小值
            max[0] = nums[0];
            min[0] = nums[0];
            int res = nums[0];
            for(int i = 1;i < nums.length;i++) {
                // 以该数结尾的乘积的最大值有三种可能
                max[i] = Math.max(nums[i], Math.max(nums[i] * max[i - 1], nums[i] * min[i - 1]));
                // min也有三种可能
                min[i] = Math.min(nums[i], Math.min(nums[i] * max[i - 1], nums[i] * min[i - 1]));
                res = Math.max(res, max[i]);
            }
            return res;
        }
    }