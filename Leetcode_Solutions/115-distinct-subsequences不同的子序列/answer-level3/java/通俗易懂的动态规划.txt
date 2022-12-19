## Solution:

### what?

找出一个字符串中包含指定序列的个数（序列并不一定连续，但在字符串相对顺序保持不变）。

### how?

遇到有关字符串的编程问题，十有八九要用到动态规划，因为如果我们要暴力枚举字符串中所有的序列情况，时间复杂度是指数级别的，不可取。

事实上，在用字符串`S`的序列和`T`进行匹配时，会用到已经匹配好的部分前缀序列，这里体现了动态规划求解所需要的子问题重叠性质。

接下来，需要找到最优子结构。假设我们匹配字符串`S`第`i`个字符和字符串`T`第`j`个字符，如果这两个字符相等，我们需要考虑选不选$T_j$这个字符，这里就产生了两种情况：
- **选**：$S_{0~i-1}$中匹配了$T_{0~j-1}$的序列个数
- **不选**：$S_{0~i-1}$中匹配了$T_{0~j}$的序列个数
  
如果这两个字符不相等的话，我们直接用**不选**的情况。

`dp[i][j]`:表示字符串$S$前缀$S_{0i}$匹配了字符串$T$前缀$T_{0j}$的序列个数。

状态转移方程：

当$S(i)=T(j),dp[i][j]=dp[i-1][j-1]+dp[i-1][j]$ 

当$S(i)!=T(j),dp[i][j]=dp[i-1][j]$

最后返回$dp[S.length][T.length]$即字符串$S$包含字符串$T$的序列个数。

```java
//19ms
class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();
        if(m==0 || n==0) return 0;
        int[][] dp = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<Math.min(i+1, n); j++) {
                if(i == 0) {
                    dp[0][0] = (s.charAt(i) == t.charAt(j))? 1 : 0;
                }else if(j == 0){
                    dp[i][0] = (s.charAt(i) == t.charAt(j))? dp[i-1][0]+1 : dp[i-1][0];
                }else {
                    dp[i][j] = (s.charAt(i) == t.charAt(j))? dp[i-1][j-1]+dp[i-1][j] : dp[i-1][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
}
```

### Complexity:

- $T:O(mn)$ 
- $S:O(mn)$ 

m为字符串Ｓ长度，n为字符串T长度