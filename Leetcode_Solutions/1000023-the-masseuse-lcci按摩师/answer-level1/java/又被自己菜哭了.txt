### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
        int a = 0, b = 0;
        int ans = 0;
        for(int i = 0; i < nums.length; i++){
            ans = Math.max(b, a + nums[i]);
            a = b;
            b = ans;
        }
        return ans;
    }
}
```

```java
class Solution {
    public int massage(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        if(nums.length == 1){
            return nums[0];
        }

        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        for(int i = 2; i < nums.length; i++){
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[dp.length-1];
    }
}
```