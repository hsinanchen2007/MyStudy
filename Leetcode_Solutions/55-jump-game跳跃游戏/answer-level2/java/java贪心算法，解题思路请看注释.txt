```
class Solution {
    public boolean canJump(int[] nums) {
        int max = 0;//设定最远可到达的位置，初始为0
        for(int i = 0; i <= max; i++){
            max = Math.max(nums[i] + i,max);//当前位置可到达的最远位置与之前记录最远位置，取最大值
            if(max >= nums.length - 1) return true;//如果最远可到达的位置大于数组长度，则可到达
        }
        return false;//其他情况无法到达
    }
    
}
```
