  private  boolean canJump(int[] nums) {

    int j = nums.length - 1;

    for (int i = nums.length - 2; i >= 0; i--) {

      if (j - i <= nums[i]) {
        j = i;
      }
    }
    //看做好一步
    return j == 0;
  }