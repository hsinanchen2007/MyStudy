统计一下0，1，2的个数，按照0，1，2的顺序放到数组就行

public void sortColors(int[] nums) {
        if(nums == null || nums.length == 0 || nums.length == 1){
            return;
        }
        int a = 0;
        int b = 0;
        int c = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i] == 0){
                a++;
            }else if(nums[i] == 1){
                b++;
            }else if(nums[i] == 2){
                c++;
            }
        }
        int index = 0;
        for(;a>0;a--){
            nums[index++] = 0;
        }
        for(;b>0;b--){
            nums[index++] = 1;
        }
        for(;c>0;c--){
            nums[index++] = 2;
        }
    }