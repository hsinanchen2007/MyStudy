    public int findDuplicate(int[] nums) {
        for (int i = 0; i < nums.length; i++){
            if (nums[Math.abs(nums[i])] < 0)return nums[i];
            nums[nums[i]] = -nums[nums[i]];
        }
        return -1;
    }