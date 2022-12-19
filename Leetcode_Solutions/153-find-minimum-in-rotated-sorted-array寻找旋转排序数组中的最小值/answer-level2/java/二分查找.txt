特殊值点要注意
-class Solution {
    public int findMin(int[] nums) {
        int N=nums.length;
        int mid=(N-1)/2;
        boolean unfinded=true;
        int begin=0;
        int end=N-1;
        if(N==1||nums[0]<nums[N-1]){
            return nums[0];
        }
        else{
        while(unfinded){
            if(nums[mid]>nums[mid+1])
            {
                unfinded=false;

            }
            else if (nums[mid]>=nums[begin]){

                begin=mid+1;
                mid=(begin+end)/2;
            }
            else
            {
                end=mid-1;
                mid=(begin+end)/2;
            }

        }
        }
        return nums[mid+1];
    }
}