### 解题思路
$f[i][j]$表示A[0..i-1]与B[0..j-1]的匹配结果

### 代码

```java []
class Solution {
    public boolean isMatch(String s, String p) {
        int N = s.length();
        int M = p.length();

        char []A = s.toCharArray();
        char []B = p.toCharArray();

        // define f[i][j]
        boolean [][] f = new boolean[N+1][M+1];

        for(int i=0; i<=N; ++i)
            for(int j=0; j<=M; ++j){
                if(i==0 && j==0){
                    f[i][j] = true;
                    continue;
                }
                if(j == 0){
                    f[i][j] = false;
                    continue;
                }
                // j>0
                if(B[j-1]!='*'){
                    if(i>0 && (A[i-1] == B[j-1] || B[j-1]=='?'))
                        f[i][j] = f[i-1][j-1];
                }
                else{
                    // 0个
                    f[i][j] = f[i][j-1];
                    if(i > 0)
                        // 多个
                        f[i][j] = f[i][j] || f[i-1][j];
                }
            }
        return f[N][M];
    }
}
```
```python []
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        N, M = len(s), len(p)

        f = [[False for _ in range(M+1)] for _ in range(N+1)]

        for i in range(N+1):
            for j in range(M+1):
                if i==0 and j==0:
                    f[i][j] = True
                    continue
                if j == 0:
                    f[i][j] = False
                    continue

                # j > 0
                if p[j-1] != '*':
                    if i>0 and (s[i-1]==p[j-1] or p[j-1]=='?'):
                        f[i][j] = f[i-1][j-1]
                    
                else:
                    # *匹配0个字符
                    f[i][j] = f[i][j-1]
                    if i > 0:
                        # *匹配多个字符
                        f[i][j] = f[i][j] or f[i-1][j]

        return f[N][M]
```
```c++ []
class Solution {
public:
    bool isMatch(string A, string B) {
        // B为模式串, 从后至前分析B串的组成
        // 当B[n-1]是一个常规字符, if A[m-1]==B[n-1], 匹配结果取决于A[0..m-2]与B[0..n-2]的匹配
        // 当B[n-1]='?', 匹配结果取决于A[0..m-2]与B[0..n-2]
        // 当B[n-1]='*', 如果A[m-1]不被B[n-1]匹配, 匹配结果取决于A[0..m-1]与B[0..n-2]匹配结果
        // 如果A[m-1]被B[n-1]匹配, 匹配结果取决于A[0..m-2]与B[0..n-1]匹配结果(0或多个)

        // 状态: f[i][j]为A[0..i-1]与B[0..j-1]的匹配结果
        // 方程: f[i][j] = f[i-1][j-1], if i>0 && (B[j-1]='?' or A[i-1]==B[j-1])
        //       f[i][j] = f[i-1][j] or f[i][j-1] if B[j-1]='*'

        int N = A.size();
        int M = B.size();

        vector<vector<bool>> f = vector<vector<bool>>(N+1, vector<bool>(M+1, false));

        for(int i=0; i<=N; ++i)
            for(int j=0; j<=M; ++j){
                if(i == 0 && j==0){
                    f[i][j] = true;
                    continue;
                }
                // 当模式串为空, 且A不为空时, f[i][j] = false
                if(j == 0){
                    f[i][j] = false;
                    continue;
                }
                // j>0
                if(B[j-1] != '*'){
                    if(i>0 && (A[i-1]==B[j-1] || B[j-1]=='?'))
                        f[i][j] = f[i-1][j-1];
                }
                // 当B[j-1]='*'
                else{
                    f[i][j] = f[i][j-1];
                    if(i > 0)
                        f[i][j] = f[i][j] || f[i-1][j];
                }
            }
        
        return f[N][M];
    }
};
```