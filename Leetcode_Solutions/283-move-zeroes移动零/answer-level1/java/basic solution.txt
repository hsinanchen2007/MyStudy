class Solution {
    public void moveZeroes(int[] nums) {
         if (nums == null || nums.length <= 1) {
        return;
    }
        int r=nums.length-1;
        for(int i=0;i<=r;){
            if(nums[i]==0){
               // int temp=nums[i];
                    for(int j=i;j<r;j++){
                        nums[j]=nums[j+1];
                    }
                nums[r--]=0;  
            }
            else i=i+1;
        }
        return ;
    }
}