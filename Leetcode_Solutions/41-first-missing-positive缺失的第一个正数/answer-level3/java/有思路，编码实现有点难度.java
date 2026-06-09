```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if(nums==null || nums.length<=0){
            return 1;
        }
        int n=nums.length;
        for(int i=0;i<n;i++){
           while(nums[i]<n && nums[i]>=1 && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
               int temp=nums[i];
               nums[i]=nums[temp-1];
               nums[temp-1]=temp;
           }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
}
```