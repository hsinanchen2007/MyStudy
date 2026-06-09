class Solution {
    public int[] exchange(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        while(low<high){
            if(nums[low]%2==0 && nums[high]%2==1){
                int tmp=nums[low];
                nums[low]=nums[high];
                nums[high]=tmp;
                low++;
                high--;
            }else if(nums[low]%2==1){
                low++;
            }else if(nums[high]%2==0){
                high--;
            }
        }
        return nums;
    }
}