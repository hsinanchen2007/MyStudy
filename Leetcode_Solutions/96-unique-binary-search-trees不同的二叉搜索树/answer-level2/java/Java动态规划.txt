### 解题思路
总长度为n， 则
以 j 为根节点的二叉搜索树的情况有  dp[j-1] * dp[n - j], 即左子树所有可能情况 和 右子树所有可能情况的笛卡尔积

### 代码

```java
class Solution {
    public int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        
        for(int i=3; i < n + 1; i++){
            for(int j=1; j < i + 1; j++){
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
}
```