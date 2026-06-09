
# 最接近的三数之和 (暴力枚举+贪心)
    class Solution {
        public int threeSumClosest(int[] nums, int target) {
            int i=0,j=0,k=0;
            int sum = 0;
            int len = 0;
            int minLen = 999999999;
            int res = 0;
            boolean bFlag = false;
            Arrays.sort(nums);
            for(i=0;i<nums.length;i++){
                for(j=i+1;j<nums.length;j++){
                    for(k=nums.length-1;k>j;k--){
                        sum = nums[i]+nums[j]+nums[k];
                        len = Math.abs(sum - target);
                        if(len<minLen) {
                            minLen = len;
                            res = sum;
                        }
                    }
                }
            }
            return res;
        }
    }