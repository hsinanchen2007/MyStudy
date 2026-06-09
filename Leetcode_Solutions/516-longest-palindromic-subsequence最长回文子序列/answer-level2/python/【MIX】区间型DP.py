### 解题思路
时间复杂度$O(N^2)$, 时间复杂度$O(N^2)$

### 代码

```java []
class Solution {
    public int longestPalindromeSubseq(String s) {
        // 定义f[i][j] 表示S[i..j]中最长回文子序列
        // f[i][j] = max(f[i+1][j], f[i, j-1], f[i+1, j-1]+2 | S[i]==S[j])

        int N = s.length();
        if(N <= 1)
            return 1;
        char []ss = s.toCharArray();
        int[][] f = new int[N][N];

        // init
        for(int i=0; i<N; ++i)
            f[i][i] = 1;

        for(int i=0; i<N-1; ++i)
            if(ss[i] == ss[i+1])
                f[i][i+1] = 2;
            else
                f[i][i+1] = 1;

        // loop length
        for(int len=3; len<=N; ++len){
            for(int i=0; i<=N-len; ++i){
                int j = i+len-1;
                f[i][j] = Math.max(f[i+1][j], f[i][j-1]);
                if(ss[i] == ss[j])
                    f[i][j] = Math.max(f[i][j], f[i+1][j-1]+2); 
            }
        }
        
        return f[0][N-1];
    }
}
```
```python []
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        N = len(s)
        if N == 0:
            return 0

        # f[i][j] S[i...j]中的最长回文子序列
        # 状态转移方程
        # f[i][j] = max(f[i+1][j], f[i][j-1], f[i+1][j-1]+2 | S[i]==S[j])

        f = [[0 for _ in range(N)] for _ in range(N)]

        # init
        for i in range(N):
            f[i][i] = 1

        for i in range(0, N-1):
            f[i][i+1] = 2 if s[i] == s[i+1] else 1

        # loop length
        for L in range(3, N+1):
            for i in range(0, N-L+1):
                j = i+L-1
                f[i][j] = max(f[i+1][j], f[i][j-1])
                if s[i] == s[j]:
                    f[i][j] = max(f[i][j], f[i+1][j-1]+2)


        return f[0][N-1]
```
```c++ []
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 区间型dp
        // 确定状态 f[i][j]表示S[i...j]的最长回文子串的长度
        // 转移方程 f[i][j]=max(f[i+1][j], f[i][j-1], f[i+1][j-1]+2 | S[i]==S[j])
        // 按照区间长度顺序计算
        int N = s.size();
        if(N == 0)
            return 0;

        if(N == 1)
            return 1;

        auto f = vector<vector<int>>(N, vector<int>(N, 0));
        // init
        for(int i=0; i<N; ++i)
            f[i][i] = 1;

        for(int i=0; i<N-1; ++i){
            if(s[i] == s[i+1])
                f[i][i+1] = 2;
            else
                f[i][i+1] = 1; 
        }

        // iterate length
        for(int len = 3; len<=N; ++len){
            for(int i=0; i<=N-len; ++i){
                int j = i+len-1;
                f[i][j] = max(f[i+1][j], f[i][j-1]);
                if(s[i] == s[j])
                    f[i][j] = max(f[i][j], f[i+1][j-1]+2);
            }
        }

        return f[0][N-1];
    }
};
```