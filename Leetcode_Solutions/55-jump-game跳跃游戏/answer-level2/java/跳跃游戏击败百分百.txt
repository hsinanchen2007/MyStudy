public  boolean canJump(int[] nums) {

        int step = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] >= step) {
                step = 1;
            } else {
                step++;
            }
        }

        return step == 1;
    }