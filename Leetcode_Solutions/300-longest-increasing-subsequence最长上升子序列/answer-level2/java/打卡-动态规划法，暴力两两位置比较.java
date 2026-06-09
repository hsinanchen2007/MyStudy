### 解题思路
动态规划法，dp数组保存当前位置结尾时的最长子序列，暴力二维循环，每个位置与其前每个位置比较，如果比那个位置大，那么有dp[i] = Math.max(dp[i], dp[j] + 1); 同时注意更新整个数组的最长子序列max

### 代码

```java
class Solution {
    // 想法：动态规划，dp[i]何存以i+1个元素结尾的最长的子序列，第i+1个元素如果大于前i个元素中的第j个，那
    // 么第i+1元素的最长子序列应为max(第i+1个元素最长子序列, 第j个元素最长子序列+1)，复杂度为O(n2)
    public int lengthOfLIS(int[] nums) {
        int max = nums.length == 0 ? 0 : 1;
        int dp[] = new int[nums.length];
        Arrays.fill(dp, 1);
        
        for(int i = 1; i < nums.length; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                    if(dp[i] > max){
                        max = dp[i];
                    }
                }
            }
        }
        
        return max;
    }
}
```