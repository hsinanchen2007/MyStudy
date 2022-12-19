```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        //cnt计数
        int cnt = 0;
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            //如果数为1，计数加
            if(nums[i]==1) cnt++;
            //为0，断开了，不连续，归零
            else{
                cnt=0;
            }
            //记录最大值
            max = Math.max(max, cnt);            
        }
        return max;
    }
}
```

