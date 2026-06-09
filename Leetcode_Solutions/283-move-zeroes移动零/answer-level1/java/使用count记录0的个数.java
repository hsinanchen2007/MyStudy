    public void moveZeroes(int[] nums) {
        int count =0;//记录0
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==0){
                count++;
            }else
            {
                //向前移动count位
                if(count>0){
                    nums[i-count]=nums[i];
                }
            }
        }
        if(count>0)
            Arrays.fill(nums,nums.length-count,nums.length,0);
    }
**使用count计数，并且辅助值的移动**