```
public void moveZeroes(int[] nums) {
        int zeroCount=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                zeroCount++;
            }else{
                int temp=nums[i];
                nums[i]=nums[i-zeroCount];
                nums[i-zeroCount]=temp;
            }
        }
    }
```
