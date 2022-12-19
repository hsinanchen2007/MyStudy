```
class Solution {
    //根据二分法的特性来做：用二分查找法在数组中寻找一个不存在的数num，
    //最后mid一定会指向num相邻的两个数的其中一个。
    //所有这道题的解法是用两次二分法找出target+-0.1的相邻的数。
    //再找出target的起始和终点索引。
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0) return new int[]{-1,-1};
        double d1 = target - 0.1;
        double d2 = target + 0.1;
        int left=0,right=0;
        int start = 0,end = nums.length-1;

        while(start <= end){
            left = start + (end-start)/2;
            //不会存在d1等于数组中某一个元素的情况
            if(nums[left]<d1){
                start = left+1;
            }else{
                end = left-1;
            }
        }

        start = 0;
        end = nums.length-1;
        while(start <= end){
            right = start + (end-start)/2;
            if(nums[right]<d2){
                start = right+1;
            }else{
                end = right-1;
            }
        }

        //数组中没有target
        if(nums[left]!=target && nums[right]!=target && (left+1==right || left==right)){
            return new int[]{-1,-1};
        }
        //数组中一定存在target，找出起点索引和终点索引
        if(nums[left] != target) left++;
        if(nums[right] != target) right--;
        return new int[]{left,right};
    }
}
```
