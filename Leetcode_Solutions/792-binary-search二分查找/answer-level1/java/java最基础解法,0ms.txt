class Solution {
    public int search(int[] nums, int target) {
        int min=0;
        int max=nums.length-1;//从两端点开始
        int mid=(min+max)/2;//傻蛋求解中位数
        while(nums[mid]!=target){
            if (nums[mid]>target){
                max=mid-1;
            }else{
                min = mid+1;
            }
            if(min>max){
                return -1;
            }
            mid=(max+min)/2;
        }
        return mid;
    }
}