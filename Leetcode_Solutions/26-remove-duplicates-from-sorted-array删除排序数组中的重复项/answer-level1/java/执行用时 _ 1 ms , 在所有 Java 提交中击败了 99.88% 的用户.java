class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 1) return 1;
        int curr = 1, pre = 0;
        // 遍历整个数组
        for(int i = 1; i < nums.length; i++)
        {
            if(nums[curr] != nums[i])
            {
                nums[curr] = nums[i];
            }
            if(curr < nums.length && nums[curr] != nums[pre])
            {
                pre = curr++;
            }
        }
        return curr;
    }
}