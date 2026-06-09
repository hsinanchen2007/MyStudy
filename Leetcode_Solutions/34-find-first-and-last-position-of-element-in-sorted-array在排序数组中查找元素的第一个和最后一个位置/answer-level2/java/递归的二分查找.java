```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {nums.length,-1};
        midSearch(nums,target,0,nums.length-1,res);
        if(res[0]==nums.length)res[0]=-1;
        return res;
    }
    private void midSearch(int[] nums,int target,int left,int right,int[]res){
        if(left>right)
            return;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                res[0] = Math.min(res[0],mid);
                res[1] = Math.max(res[1],mid);
                midSearch(nums,target,left,mid-1,res);
                midSearch(nums,target,mid+1,right,res);
                return;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
}
```
