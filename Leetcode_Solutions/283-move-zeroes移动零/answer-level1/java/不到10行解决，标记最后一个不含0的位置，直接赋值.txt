        public void moveZeroes(int[] nums) {
            int lastNonZeroIndex = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    //如果不是一个位置，index赋值nums[i],nums[i] =0
                    if (i != lastNonZeroIndex) {            
                        nums[lastNonZeroIndex] = nums[i];    
                        nums[i] = 0;
                    }
                    //位置向后移动
                    lastNonZeroIndex++;
                }
            }
        }