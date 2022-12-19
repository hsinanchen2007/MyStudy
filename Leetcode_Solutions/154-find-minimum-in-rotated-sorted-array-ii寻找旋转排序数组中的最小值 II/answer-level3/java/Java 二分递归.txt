思路：刚开始尝试二分，发现首尾数字相同时，分析比较复杂。因此采用二分递归，实现很简单。
```
class Solution {
    public int findMin(int[] nums) {
        return findmin(nums,0,nums.length-1);
    }
    public int findmin(int[] nums,int start,int end){
        if(start == end) return nums[start];
        int mid = (start+end)>>>1;
        return Math.min(findmin(nums,start,mid), findmin(nums,mid+1,end));
    }
}
```
