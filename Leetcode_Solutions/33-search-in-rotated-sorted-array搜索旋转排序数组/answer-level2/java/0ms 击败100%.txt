```
class Solution {
    public int search(int[] nums, int target) {
        int left=0,right=nums.length-1;
        while (right>=left){
            int mid=(left+right)>>>1;
            int midVal=nums[mid];
            if(midVal==target)
                return mid;
            if(midVal>nums[left]&&target>=nums[left]&&target<midVal||midVal<nums[left]&&(target>=nums[left]||target<midVal))
                right=mid-1;
            else
                left=mid+1;
        }
        return -1;
    }
}
```