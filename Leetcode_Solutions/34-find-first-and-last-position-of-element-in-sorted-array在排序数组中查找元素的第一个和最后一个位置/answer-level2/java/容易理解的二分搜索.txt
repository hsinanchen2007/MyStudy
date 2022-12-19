```
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int a = search(nums,target);
        int b = search(nums,target+1);
        if(a == nums.length|| nums[a] != target )
            return new int[]{-1,-1};
        return new int[]{a,b-1};
    }

    public int search(int[] nums,int target){
        int left = 0;
        int right = nums.length;
        while(left<right)
        {
            int mid = (right+left)>>>1;
            if(nums[mid]>=target)
                right = mid;
            if(nums[mid]<target)
                left = mid +1;
        }
        return left;
    }
}
```
