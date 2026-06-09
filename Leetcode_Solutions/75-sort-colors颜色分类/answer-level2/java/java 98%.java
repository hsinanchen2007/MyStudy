```
class Solution {
    public void sortColors(int[] nums) {
        if(nums==null||nums.length==0){
            return;
        }
        int[] intcounts = new int[3];
        for(int i =0;i<nums.length;i++){
            intcounts[nums[i]]++;
        }
        for(int i = 0,j=0;i<3;i++){
            while(intcounts[i]>0){
                nums[j++]=i;
                intcounts[i]--;
            }
        }
    }
}
```
