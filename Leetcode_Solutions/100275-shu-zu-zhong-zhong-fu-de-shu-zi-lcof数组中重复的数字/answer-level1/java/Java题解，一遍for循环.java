class Solution {
    public int findRepeatNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
            if(nums[i]==nums[nums[i]] && i!=nums[i]){ // 判断当前元素和以当前元素为下标的元素是否相等
                return nums[i];
            }else { // 交换两个元素顺序
                int tmp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = tmp;
            }
        }
        return -1;
    }
}