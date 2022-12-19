```
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if(nums.length == 0 || nums == null) return 0;
        int cnt = 1; //注意初始化为1，因为数组不空，最短也是单个数
        int max = 1; //记录cnt最大值
        //1遍循环，从头开始遍历，当符合递增时，cnt++；不符合，cnt归1
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i+1] > nums[i]){
                cnt++;
                max=Math.max(max,cnt);
            }
            else
                cnt=1;
        }
        return max;
    }
}
```
