如果和为负，则重新选集合
否则{
    如果新加数后和为正，则加进去，并更新最大和的值；
    否则：重新选集合
    }
```
class Solution {
    public int maxSubArray(int[] nums) {
        int sum=nums[0],max=nums[0];
        for(int i=1;i<nums.length;i++){
            if(sum<=0){
                sum=nums[i];
                if(sum>max)max=sum;
            }
            else{
                if(sum+nums[i]>0){
                    sum+=nums[i];
                    if(sum>max)max=sum;
                }else{
                    sum=nums[i];
                }
            } 
        }
        return max;
    }
}
```
