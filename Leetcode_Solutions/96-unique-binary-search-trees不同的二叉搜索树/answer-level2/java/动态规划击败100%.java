![屏幕快照 2019-09-08 下午6.16.38.png](https://pic.leetcode-cn.com/6a15b6f613ee6354c41f74495099eca679ba0de04ea9fc8f56bb8853c9454bec-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-09-08%20%E4%B8%8B%E5%8D%886.16.38.png)
思路如下：
当只有0，1，2个节点时，树种类有1，1，2种
当n > 2时，刨除根结点，还有n-1个闲置节点，给左子树分配i个，右子树剩余n-1-i个，
因此有dp[n] = dp[i]*dp[n-i-1]
```
public int numTrees(int n) {
        if(n < 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            int cur = 0;
            for(int j = 0; j < i; j++){
                cur += dp[j]*dp[i-1-j];
            }
            dp[i] = cur;
        }
        return dp[n];
}
```
