### 解题思路
$dp[i][j]$表示$s[0...i-1]$与$p[0...j-1]$是否匹配

### 代码

**双序列dp**
```java []
class Solution {
    public boolean isMatch(String s, String p) {
        // dp[i][j]表示s[0...i-1]与p[0...j-1]之间的匹配结果
        int N = s.length()+1;
        int M = p.length()+1;

        boolean [][]dp = new boolean[N][M];
        dp[0][0] = true;

        for(int i=0; i<p.length(); ++i){
            if(i>0 && p.charAt(i)=='*' && dp[0][i-1])
                dp[0][i+1] = true;
        }

        // 遍历两个字符串
        for(int i=0; i<s.length(); ++i)
            for(int j=0; j<p.length(); ++j){
                if(p.charAt(j) == s.charAt(i))
                    dp[i+1][j+1] = dp[i][j];
                if(p.charAt(j) == '.')
                    dp[i+1][j+1] = dp[i][j];
                if(j>0 && p.charAt(j) == '*'){
                    if(p.charAt(j-1)!=s.charAt(i) && p.charAt(j-1)!='.'){
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }else{
                        dp[i+1][j+1] = dp[i][j] || dp[i+1][j-1] || dp[i][j+1];
                    }
                }
            }
        return dp[N-1][M-1];
    }
}
```
```python []
class Solution:
    def isMatch(self, A: str, B: str) -> bool:
    # .*可以匹配任意字符, 因为.* = .........(0个或者多个), 每个.都可以匹配任意字符
    # B[n-1]是一个字符, 当A[m-1] = B[n-1], 匹配结果与A[0..m-2]与B[0..n-2]一致
    # B[n-1]是'.', A[m-1]一定与B[n-1]匹配, 匹配结果与A[0..m-2]与B[0..n-2]一致
    # B[n-1]是'*', 则B[n-2]可以重复0次或多次, 考虑A[m-1]是0个B[n-2]还是多个B[n-2]中的最后一个
    # case 1: A[m-1]是0个B[n-2], 匹配结果与A[0..m-1]与B[0..n-3]是否一致
    # case 2: A[m-1]是多个B[n-2]中的最后一个, 匹配结果与A[0..m-2]与B[0..n-1]

    # 状态: f[i][j]: A[0..i-1]与B[0..j-1]能否匹配
    # 方程: case 1 f[i][j] = f[i-1][j-1] && (B[j-1]=='.' or B[j-1]==A[i-1])
    #       case 2 f[i][j] = f[i][j-2] or (f[i-1][j] and (B[j-2]=='.' or B[j-2]==A[i-1])) if B[j-1]=='*'

        N, M = len(A), len(B)
        f = [[False for _ in range(M+1)] for _ in range(N+1)]

        for i in range(N+1):
            for j in range(M+1):
                if i==0 and j==0:
                    f[i][j] = True
                    continue
                
                # i>0
                if j==0:
                    f[i][j] = False
                    continue
                
                f[i][j] = False
                if B[j-1] != '*':
                    if i>0 and (B[j-1]=='.' or B[j-1]==A[i-1]):
                        f[i][j] = f[i-1][j-1]
                
                if B[j-1] == '*':
                    if j>1:
                        f[i][j] = f[i][j] or f[i][j-2]
                    if i>0 and j>1:
                        if B[j-2] == '.' or B[j-2]==A[i-1]:
                            f[i][j] = f[i][j] or f[i-1][j]

        return f[N][M]
```
```c++ []
class Solution {
public:
    bool isMatch(string s, string p) {
        // dp求解
        int N = s.length()+1;
        int M = p.length()+1;

        // 定义dp[i][j]表示s[0...i-1]与p[0...j-1]是否匹配
        vector<vector<bool>> dp(N, vector<bool>(M, false));
        dp[0][0] = true;
        // 匹配首字符
        for(int i=0; i<p.length(); ++i)
            if(i > 0 && p[i] == '*' && dp[0][i-1]){
                // dp[0][i] = true;
                dp[0][i+1] = true;
            }

        for(int i=0; i<s.length(); ++i)
            for(int j=0; j<p.length(); ++j){
                if(p[j] == s[i])
                    dp[i+1][j+1] = dp[i][j];
                // 正则表达式可以匹配任何字符
                if(p[j] == '.')
                    dp[i+1][j+1] = dp[i][j];
                // 正则表达式匹配前面的字符
                if(j > 0 && p[j] == '*'){
                    if(p[j-1] != s[i] && p[j-1]!='.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else
                        dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1];
                }
            }
        return dp[N-1][M-1];
    }
};
```
**内置正则**
```java []
class Solution {
    public boolean isMatch(String s, String p) {
        return s.matches(p);
    }
}
```
```python []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        import re
        res = re.match(p, s)
        if res:
            return res.group() == s
        return False
```