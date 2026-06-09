### 解题思路
动态规划，dp数组每一个位置记录的是当前位置处以前的最长上升序列<br>
最后只需要将dp中的最大数返回即可

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length == 0) return 0;
        int n = nums.length;
        int[] dp = new int[n];
        for(int i = 0; i < n; i++){
            int max = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    max = Math.max(max, dp[j]+1);
                }
            }
            dp[i] = max;
        }
        int  result = 0;
        for(int x : dp){
            result = Math.max(result, x);
        }
        return result;
    }
}
```