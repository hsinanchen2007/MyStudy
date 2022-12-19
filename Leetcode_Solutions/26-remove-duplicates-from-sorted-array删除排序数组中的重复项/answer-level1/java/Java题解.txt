class Solution {
    public int removeDuplicates(int[] nums) {
        int low=0;
        for(int i=1;i<nums.length;i++){
            if(nums[low]!=nums[i]){
                low++;
            }
            nums[low]=nums[i];
        }
        return low+1;
    }
}
