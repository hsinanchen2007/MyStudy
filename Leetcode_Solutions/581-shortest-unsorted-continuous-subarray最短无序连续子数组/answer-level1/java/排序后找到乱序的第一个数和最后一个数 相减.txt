 public int findUnsortedSubarray(int[] nums) {
       int[] snums=nums.clone();
        Arrays.sort(nums);
        int count=0,stop=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=snums[i]){
                count=i-1;
                break;
            }
        }
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=snums[i]){
                stop=i;
            }
        }
       return stop-count;
    }