```
    public boolean uniqueOccurrences(int[] arr) {
       public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int len=nums.length;
        if(len==1){
            return nums[0];
        }else if(nums[0]!=nums[1]){
            return nums[0];
        }else if(nums[len-1]!=nums[len-2]){
            return nums[len-1];
        }
        int i=0;
        while(i<len){
            if(nums[i]==nums[i+1]){
                i=i+3;
            }else{
                return nums[i];
            }
        }
        return -1;
    }
```
