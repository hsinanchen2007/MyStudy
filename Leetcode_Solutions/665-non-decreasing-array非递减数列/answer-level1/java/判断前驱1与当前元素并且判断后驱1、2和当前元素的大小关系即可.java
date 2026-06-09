class Solution {
    public boolean checkPossibility(int[] nums) {
        int i = 0;int count = 0;int end = nums.length - 1;
        while(i<= end -1){
            if(nums[i] > nums[i + 1]){
              count++;
                if(count>1 || (i + 2) <= end && (nums[i] > nums[i + 2]) && (i-1)>=0 && (nums[i-1] > nums[i + 1])){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
}