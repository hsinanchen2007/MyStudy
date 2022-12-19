
代码：（懂的都懂）
```
class Solution {
    public int maxProduct(int[] nums) {
        int max=nums[0];
        for(int i=0;i<nums.length;i++){
            int tmp=nums[i];
            for(int j=i+1;j<nums.length;j++){
                if(tmp*nums[j]>max){
                    max = tmp*nums[j];
                    tmp=tmp*nums[j];
                }
                else tmp=tmp*nums[j];
                    
            }
            if(nums[i]>max) max = nums[i];
        }
        return max;
    }
}
```
