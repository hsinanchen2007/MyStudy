class Solution {
    public int threeSumClosest(int[] nums, int target) {
      int sum = Integer.MAX_VALUE;
        int res = Integer.MIN_VALUE;
        Arrays.sort(nums);
        for (int k = 0; k < nums.length -2; k++){
            int i = k+1;
            int j = nums.length -1;
            while (i < j){
                int tmp = nums[k] + nums[i] + nums[j];
                int diff = Math.abs(tmp - target);
                if (diff <= sum){
                    sum = diff;
                    res = tmp;
                }
               if (tmp > target){
                   j--;
               }else if (tmp < target){
                   i++;
               }else {
                   return tmp;
               }
            }
        }
        return res;
    }
}