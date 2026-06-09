
首要目的是不停的让target落在一个已经排好的小段里，随后进行二分查找
通过判断midNum和start/end的关系，先找到已经排好序的半段，然后不停的递归。


```
class Solution {
    public int search(int[] nums, int target) {
        return work(nums, 0, nums.length-1, target);
    }
    
    public int work(int [] nums, int start, int end, int target ){
        if(nums.length<=start||nums.length<=end) return -1;
        if(nums[start]==target) return start;
        if(nums[end]==target) return end;
        if(start>=end) return -1;
        
        int mid = (start+end)/2;
        int midNum = nums[mid];
        
        if(midNum==target) return mid;
        
        if(midNum>nums[start]){ //左边是排好的
            if(target<midNum&&target>nums[start]){
                return work(nums, start, mid, target);
            }else{
                return work(nums, mid+1,end, target);
            }
            
        }else{ //右边是排好的
            if(target<nums[end] && target>=nums[mid+1]){
                return work(nums, mid+1, end, target);
            }else{
                return work(nums, start, mid, target);
            }
        }
        
    }
}
