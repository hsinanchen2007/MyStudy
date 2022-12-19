### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        // 几种特殊情况
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return Math.max(nums[0], nums[1]);
        }
        if(n == 3){
            int tem = Math.max(nums[0], nums[1]);
            return Math.max(tem, nums[2]);
        }
        
        // 一定搜第一个屋子,最后一个屋子就不搜了
        int[] dp1 = new int[n-1];
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for(int i = 2; i < n - 1; i++){
            dp1[i] = Math.max(dp1[i-1], dp1[i-2] + nums[i]); 
        }
        // 一定不搜第一个房子
        int[] dp2 = new int[n];
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 2; i < n; i++){
            dp2[i] = Math.max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return Math.max(dp1[n-2], dp2[n-1]);
    }
}
```