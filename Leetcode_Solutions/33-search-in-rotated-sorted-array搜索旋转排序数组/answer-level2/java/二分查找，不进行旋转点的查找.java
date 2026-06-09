/*思路：
    1.先把序列对半分成两部分
    2.如果右半部分是有序数列，
      判断target是否位于[nums(mid),nums(high)] 单调区间内，如果是，继续对这部分进行二分判断。
      如果target不在[nums(mid),nums(high)]单调区间内，
      说明target位于左半部分的非递增序列中。对左半边序列进行二分判断。
    3.如果左半部分是有序数列，即 if(nums[low] <nums[mid])
      判断target是否位于[nums(low),nums(mid)] 单调区间内，如果是，继续对这部分进行二分判断。
      如果target不在[nums(low),nums(mid)] 单调区间内，
      说明target位于右半部分的非递增序列中。对右半边序列进行二分判断。
    4.经常2或者3步骤一次后，范围缩小到了原来的N/2。
      这题用二分法很合适，时间复杂度O(logn)
    备注：最开始时，我写的先判断左半部，再判断右半部分。但通过时会错误，因为无法正确处理[3,1]这种数组。
          细想一下对于N=2的数组，确实应该先判断右边。
*/
class Solution{
    public int search(int[] nums, int target){
        return search(nums, 0, nums.length-1, target);
    }
    
    private int search(int[] nums, int low, int high, int target){
        if(low > high) 
            return -1;
        int mid = (high + low)/2;
        if(nums[mid] == target) 
            return mid;
        
        //如果右左半部分是有序数列
        if(nums[mid] <nums[high]){
            if(nums[mid] < target && target <= nums[high])     //如果target位于右半部分,则继续二分查找
                return search(nums, mid+1, high, target);
            else return search(nums, low, mid-1, target);    // 否则去找左半部分  
        }
        
        //如果(nums[mid] > nums[high]，则说明旋转点在右半部分，左半部分是有序的。
        //进行左半部分的判断。
        else{
            if(nums[low] <= target && target < nums[mid] )
                return search(nums, low, mid-1, target);    //如果target位于左半部分有序数列中,则继续二分查找
            else
                return  search(nums, mid+1, high, target);  //否则，target位于右半部分。  
        }   
    }
}