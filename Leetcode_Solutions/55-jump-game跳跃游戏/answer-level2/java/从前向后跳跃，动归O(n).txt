说下思路，定义状态dp[i]，表示第一个位置前(包括i)最远能跳到的位置，状态转移方程如下：
`dp[i] = max{dp[i-1], i + nums[i]}`
然后我们从0开始出发，看不能跳到最后，只要中间跳转的方向不是向后，就返回false, 比较简单，时间复杂度 O(n)
```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length == 0){
            return true;
        }
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        for(int i = 1; i < n ;i++){
            dp[i] = Math.max(dp[i-1], i + nums[i]);
        }
        int nextIndex = 0;
        while(nextIndex < n - 1){
            if(dp[nextIndex] <= nextIndex){ // 跳转的方向不是向后：原地 or 向前
                return false;
            }
            nextIndex = dp[nextIndex];
        }
        return true;
    }
}
```