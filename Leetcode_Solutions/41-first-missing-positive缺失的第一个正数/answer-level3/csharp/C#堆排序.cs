```
public int FirstMissingPositive(int[] nums) {
        
        int len = nums.Length;
        for(int i=0;i<len;i++){
            while(nums[i]>0&&nums[i]<len&&nums[i]-1!=i&&nums[i]!=nums[nums[i]-1]){
                Swap(nums, i, nums[i]-1);
            }
        }
        
        for(int j=0;j<len;j++){
            if(nums[j]!=j+1){
                return j+1;
            }
        }
        
        return len+1;
    }
    
    public void Swap(int[] nums, int i, int j){
        int m =0;
        m = nums[i];
        nums[i] = nums[j];
        nums[j] = m;
    }
}
```
