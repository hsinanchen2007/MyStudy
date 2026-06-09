```
    public int rob(int[] nums) {
        if(nums.length<1)return 0;
        int length = nums.length;
        if(length<4){
            Arrays.sort(nums);
            return nums[length-1];
        }
        int[] temp1 = new int[length];
        int[] temp2 = new int[length];
        int max1 = 0;
        int max2 = 0;
        for(int i = 0;i<length-1;i++){
            if(i<2){
                temp1[i]=nums[i];
                temp2[i+1]=nums[i+1];
            }
            else if(i>2){
                temp1[i]=nums[i] + Math.max(temp1[i-2],temp1[i-3]);
                temp2[i+1]=nums[i+1] + Math.max(temp2[i-1],temp2[i-2]);
            }else{
                temp1[i]=nums[i] + nums[i-2];
                temp2[i+1]=nums[i+1] + nums[i-1];
            }
        }
        max1 = Math.max(temp1[length-2],temp1[length-3]);
        max2 = Math.max(temp2[length-1],temp2[length-2]);
        return Math.max(max1,max2);
    }
```
