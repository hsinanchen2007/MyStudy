```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length==0)
            return new int[]{-1,-1};
        int left=0,right=nums.length-1;
        int[] ans = new int[2];
        //找到目标数字的第一个位置
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<target)
                left=mid+1;
            else    
                right=mid-1;
        }
        if(left>=nums.length||nums[left]!=target)
            ans[0]=-1;
        else
            ans[0]=left;
        
        left=0;
        right=nums.length-1;
        //找到目标数字的最后一个位置
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        
        if (right < 0 || nums[right] != target)
            ans[1]=-1;
        else
            ans[1] = right;
        return ans;
    }
}
```
