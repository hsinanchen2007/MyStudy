执行用时 :1 ms, 在所有 Java 提交中击败了98.23%的用户
内存消耗 :45.9 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
动态规划思想，比较基础，见下面公式。
dp[i] = max(nums[i]+dp[i-1],nums[i])  
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int dp[] = new int[nums.length+1] ;
        int ans = 0 ;
        if(nums.length!=0)
        {
            dp[0] = nums[0] ;
            ans = dp[0] ;
        }
        for(int i=1;i<nums.length;i++){
            dp[i] = Math.max(nums[i]+dp[i-1],nums[i]) ;
            if(dp[i]>ans)
                ans = dp[i] ;
        }
        return ans ;
    }
}
```