class Solution {
    public int removeDuplicates(int[] nums) {
        int i =0;
        for(int k=1;k<nums.length;k++){
            if(nums[i]!=nums[k]){
                i=i+1;
                nums[i]=nums[k];
            }
        }
        return i+1;
    }
}