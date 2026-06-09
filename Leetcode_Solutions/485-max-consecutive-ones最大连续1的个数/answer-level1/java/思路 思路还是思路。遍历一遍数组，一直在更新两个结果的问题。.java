```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        //实例化两个数 一个数当前连续1的个数。一个为最大连续1的个数。
        int count = 0;
        int maxCount = 0 ;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                count++ ;
            }else{
                //以上的思路都很好想，遇到不是1的如何操作呢。
                //更新最多一的长度。然后把当前的累加值置为0.这两步。
                maxCount = Math.max(maxCount,count) ;
                count = 0 ;
            }
        }
        return Math.max(maxCount,count) ;
    }
}
```
