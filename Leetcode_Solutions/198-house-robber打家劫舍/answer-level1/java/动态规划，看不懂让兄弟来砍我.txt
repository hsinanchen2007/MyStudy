    
    class Solution {
        public int rob(int[] nums) {
            if(nums == null || nums.length == 0){
                return 0;
            }
            int n = nums.length;
        int[] take = new int[n];
        int[] not_take = new int[n];
        take[0] = nums[0];
        not_take[0] = 0;
        for(int i = 1;i < n;i++) {
            take[i] = not_take[i - 1] + nums[i];                     //第i个情况，拿时的最大情况
            not_take[i] = Math.max(take[i - 1], not_take[i - 1]);    //第i个情况，不拿时的最大情况
        }
        return Math.max(take[n - 1], not_take[n - 1]);
        }
    }