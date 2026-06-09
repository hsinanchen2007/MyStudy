```
public class Solution {
    public int PivotIndex(int[] nums) {
        if(nums.Length==0) return -1;
        int allSum = 0,leftSum = 0;
        
        for(int i=0;i<nums.Length;i++){
            allSum+=nums[i];
        }
        

        
        for(int j=0;j<nums.Length;j++){
            if(j!=0){leftSum+=nums[j-1];}
            allSum-=nums[j];
            if(leftSum==allSum){
                return j;
            }
        }
        
        return -1;
    }
}
```
