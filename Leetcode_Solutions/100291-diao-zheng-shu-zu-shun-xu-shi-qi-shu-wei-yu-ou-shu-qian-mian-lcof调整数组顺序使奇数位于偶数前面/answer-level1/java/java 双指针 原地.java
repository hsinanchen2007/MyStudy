// ```
    public int[] exchange(int[] nums) {
        int start = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] % 2 == 1){
                //交换
                int temp = nums[start];
                nums[start] = nums[i];
                nums[i] = temp;
                start++;
            }
        }
        return nums;
    }
// ```
