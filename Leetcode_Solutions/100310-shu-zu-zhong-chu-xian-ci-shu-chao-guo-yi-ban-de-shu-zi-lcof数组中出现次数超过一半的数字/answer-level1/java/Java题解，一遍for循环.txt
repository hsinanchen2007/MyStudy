```
class Solution {
    public int majorityElement(int[] nums) {
        int vote = 0;
        int res = 0; // 假想的第一次比较的众数
        for(int i=0;i<nums.length;i++){
            if(nums[i]==res){
                vote++;
            }else{
                vote--;
            }
            if(vote<0){
                res=nums[i];
                vote=1;
            }
        }
        return res;
    }
}
```
