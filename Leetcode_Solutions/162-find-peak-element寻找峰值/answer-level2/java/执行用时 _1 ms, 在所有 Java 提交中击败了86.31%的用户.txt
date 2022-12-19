# class Solution {
/*
如果 nums[i-1] < nums[i] ，则如果 nums[i-1], nums[i], ... nums[n-1] 是单调的，则nums[n-1] 就是峰值；如果 nums[i-1], nums[i], ... nums[n-1] 不是单调的，则从 i 开始，第⼀个满⾜ nums[i] > nums[i+1] 的 i 就是峰值；所以 [i,n-1] 中⼀定包含⼀个峰值；如果 nums[i-1] > nums[i] ，同理可得 [0, i-1] 中⼀定包含⼀个峰值；
*/

    public int findPeakElement(int[] nums) {
        int l = 0 ; int r = nums.length - 1;
        while(l<r){
            int mid = l+r >>1;
            if(nums[mid] >nums[mid+1]) r=mid;
 
            else l = mid + 1;
        }
        return r;
    }
# }
