```
class Solution {
    public int arrayPairSum(int[] nums) {
        //规化出数学问题。分成两组，两组min和的最大值就是
        //数组排序，排序之后按顺序两个一组。偶数位置相加位所求信息。
        Arrays.sort(nums) ;
        int maxSum = 0 ;
        for(int i=0;i<nums.length;i++){
            //nums[0]+nums[2]+nums[4]+...+nums[2n] ;
            if(i%2==0){
                maxSum+=nums[i] ;
            }
        }
        return maxSum ;
    }
}
```
数组的规律需要求得是什么。