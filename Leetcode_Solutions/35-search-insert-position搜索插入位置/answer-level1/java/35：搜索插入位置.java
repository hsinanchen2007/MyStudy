如果目标值存在于数组中即返回索引 即nums[i] == target 时return i;
若果不存在，因为排序数组，所以第一个大于目标值的数的索引为目标值被插入的位置即nums[i] >target 时return i;
代码为：
class Solution {
    public int searchInsert(int[] nums, int target) {
        for(int i=0;i<nums.length;i++){
            if(nums[i] >= target){
               return i;
            }
        }
        return nums.length;
    }
}