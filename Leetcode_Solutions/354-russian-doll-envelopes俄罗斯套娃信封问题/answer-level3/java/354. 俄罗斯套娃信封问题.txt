### 解题思路
dp[i]表示第 i 个信封可以放入的信封数量，dfs 遍历所有信封，找到最大的那个能放入数量
时间复杂度 O(N * N)，空间复杂度 O(N)
参考链接https://leetcode-cn.com/problems/russian-doll-envelopes/solution/dfs-dp-jie-fa-by-jeffzzf/

### 代码

```java
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        if(envelopes == null || envelopes.length == 0){
            return 0;
        }

        int n = envelopes.length;
        int[] dp = new int[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            int t = dfs(envelopes, i, dp);
            ans = Math.max(ans, t);
        }
        return ans;
        
    }

    private int dfs(int[][] arr, int i, int[] dp){
        if(dp[i] != 0){
            return dp[i];
        }
        int sum = 1;
        for(int j = 0; j < arr.length; j++){
            if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]){
                sum = Math.max(sum, (1 + dfs(arr, j, dp)));
            }
        }
        dp[i] = sum;
        return sum;
    }
}
```