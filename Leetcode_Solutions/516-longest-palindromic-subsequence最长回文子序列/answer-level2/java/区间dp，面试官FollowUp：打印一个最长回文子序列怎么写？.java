### 解题思路
这是典型的区间dp，注意区分子串和子序列，子串是连续的，子序列可以不连续，这个题是子序列，可以不连续。从最后一步出发，假设S是最长回文子序列，长度为len，分析这个子序列有两种情况
- 子序列长度为1，只有一个字母
- 子序列长度大于1，必有 $S[0] = S[len-1]$

S是在区间$[i,j]$中的最长回文子序列，对于最长子序列S去头去尾后$S[1..len-2]$仍然是一个回文的，并且是在区间$[i+1,j-1]$中的最长回文子序列（应该说是在在长度为$j-i+1 - 2$时的最长回文子序列），并且可以得出$S[i,j] = S[i+1,j-1] + 2$

### 转移方程
头尾不想等，去头、去尾各一种情况；头尾相等，同时去头去尾
- $dp[i][j]$ $=$ $max${$dp[i+1][j]$$,dp[i][j-1],dp[i+1][j-1]+2$ $\&\&$$chs[i]==chs[j]$}

### 初始条件
$dp[0][0] = dp[1][1] = ...=dp[n-1][n-1] = 1$，每个字母都是长度为1的回文串
不能按照$i$去算，要按照长度$len$去算

### 代码
 写法一 递推式
```java
public int longestPalindromeSubseq(String s) {
    int n = s.length();
    if (n == 0) return 0;
    int[][] dp = new int[n][n];

    //初始化一下
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            if (s.charAt(i) == s.charAt(j)) {
                dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 2);
            }
        }
    }
    return dp[0][n - 1];
}
```

写法二：记忆化搜索
```java
public int longestPalindromeSubseq(String s) {
    int n = s.length();
    int[][] dp = new int[n][n];
    //每个位置标记为没访问过
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {   //从i开始
            dp[i][j] = -1;
        }
    }
    dfs(s, 0, n - 1,dp);
    return dp[0][n - 1];
}

private void dfs(String s, int i, int j, int[][] dp) {
    if (i > j) {
        return;
    }
    //如果计算过了就返回
    if (dp[i][j] != -1) return;
    //如果i == j，那设置下就返回
    if (i == j) {
        dp[i][j] = 1;
        return;
    }
    dfs(s, i + 1, j, dp);
    dfs(s, i, j - 1, dp);
    dfs(s, i + 1, j - 1, dp);
    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
    if (s.charAt(i) == s.charAt(j)) {
        dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 2);
    }
}

```

### FollowUp 打印一个最长回文子序列
```java
class Solution {
    // 需要对去头、去尾，相等做一些标记，需要一个path数组
    public static int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        int[][] path = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                //如果是去头,path上标记为0，如果是去尾标记为1，如果是相等，标记为2
                if (dp[i][j] == dp[i + 1][j]) {
                    path[i][j] = 0;
                } else if (dp[i][j] == dp[i][j - 1]) {
                    path[i][j] = 1;
                }
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = Math.max(dp[i][j], dp[i + 1][j - 1] + 2);
                    if (dp[i][j] == dp[i + 1][j - 1] + 2) {
                        path[i][j] = 2;
                    }
                }
            }
        }

        char[] res = new char[dp[0][n - 1]];
        //遍历s的两个指针
        int i = 0, j = n - 1;
        //填充res数组的两个指针
        int p = 0, q = dp[0][n - 1] - 1;
        while (i <= j) {
            if (i == j) {
                res[p] = s.charAt(i);
                break;
            }
            if (i + 1 == j) {
                res[p] = s.charAt(i);
                res[q] = s.charAt(j);
                break;
            }
            //其他情况，去头、去尾、相等
            if (path[i][j] == 0) {
                i++;
            } else if (path[i][j] == 1) {
                j--;
            } else {
                res[p++] = s.charAt(i++);
                res[q--] = s.charAt(j--);
            }
        }
        for (int k = 0; k < res.length; k++) {
            System.out.print(res[k] + " ");
        }
        return dp[0][n - 1];
    }
}
```