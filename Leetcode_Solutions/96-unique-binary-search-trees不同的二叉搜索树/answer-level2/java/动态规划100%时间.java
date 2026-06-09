### 解题思路
刚开始想用递归做，结果在剪切上出了问题，死活解不出来，后来用动态规划：
dp数组表示节点数可能的树结构，初始化dp[0] = 1;dp[1] = 1;dp[2] = 2;之后循环，逐步剪切一个点，然后2边的点可能的树结构总数相乘，思路上就像排列组合一样

### 代码

```java
class Solution {

    public int numTrees(int n) {
        if(n<=2) return n;  
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;++i) {
            for(int j=1;j<=i;++j) {
                dp[i] += dp[i-j] * dp[j-1];
            }          
        }
        return dp[n];
 
    }
}
```