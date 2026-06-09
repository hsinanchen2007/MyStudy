### 解题思路
时间复杂度$O(N^4)$, 空间复杂度$O(N^3)$

### 代码

```java []
class Solution {
    public boolean isScramble(String ss1, String ss2) {
        // string T & string S
        // T = T1T2  S = S1S2
        // case 1: T1是否由S1变换而来, T2是否由S2变换而来
        // case 2: T1是否由S2变换而来, T2是否由S1变换而来

        // 子问题：f[i][j][k][h]表示T[k..h]是否由S[i..j]转变而来, 满足关系h-k = j-i, 参数自由度为3
        // 由于长度一定是相同的
        // e.g. f[A][B][C]=True/False 表示S1能否通过变换转为T1,S1长度和T1的长度均为C, S1从位置A开始, T1从位置B开始
        // * 确定状态
        // f[i][j][k]表示S1能否通过变换称为T1
        // S1为S从字符i开始长度为k的子串
        // T1为T从字符j开始长度为k的子串
        // * 状态转移方程
        // f[i][j][k] = OR (f[i][j][k] AND f[i+w][j+w][k-w]) OR (f[i][j+k-w][w] AND f[i+w][j][k-w])
        // * 边界条件
        // S[i] = T[j], 则f[i][j][1]=True, else f[i][j][1]=False
        // * 计算顺序
        // 按照k从小到大的顺序进行计算
        // f[i][j][1], 0<=i<N, 0<=j<N
        // f[i][j][2], 0<=i<N-1, 0<=j<N-1
        // ...
        // f[0][0][N]

        char []s1 = ss1.toCharArray();
        char []s2 = ss2.toCharArray();
        int M = s1.length;
        int N = s2.length;

        if(M != N)
            return false;
        
        boolean [][][] f = new boolean[N][N][N+1];
        // s1[i...j] s2[k...w]
        int i, j, k, w;

        // init
        for(i=0; i<N; ++i)
            for(j=0; j<N; ++j)
                f[i][j][1] = s1[i] == s2[j];

        // loop range
        for(k=2; k<=N; ++k){
            for(i=0; i<=N-k; ++i){
                for(j=0; j<=N-k; ++j){
                    f[i][j][k] = false;
                    for(w=1; w<=k-1; ++w){
                        if(f[i][j][w] && f[i+w][j+w][k-w]){
                            f[i][j][k] = true;
                            break;
                        }
                    }

                    for(w=1; w<=k-1; ++w){
                        if(f[i][j+k-w][w] && f[i+w][j][k-w]){
                            f[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[0][0][N];
    }
}
```
```python []
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        # 扰乱字符的两种pattern
        # 区间DP
        N, M = len(s1), len(s2)
        if N!=M:
            return False

        # 定义状态f[i][j][k] \in N*N*(N+1)
        f = [[[False for _ in range(N+1)] for _ in range(N)] for _ in range(N)]

        # init
        for i in range(N):
            for j in range(N):
                if s1[i] == s2[j]:
                    f[i][j][1] = True

        # 状态转移方程
        # loop range
        for k in range(2, N+1):
            for i in range(0, N-k+1):
                for j in range(0, N-k+1):
                    f[i][j][k] = False
                    for w in range(1, k):
                        if f[i][j][w] and f[i+w][j+w][k-w]:
                            f[i][j][k] = True
                            break

                        if f[i][j+k-w][w] and f[i+w][j][k-w]:
                            f[i][j][k] = True
                            break

        return f[0][0][N]
```
```c++ []
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int N = s1.size();
        int M = s2.size();

        if(N != M)
            return false;

        // f[i][j][k]
        auto f = vector<vector<vector<bool>>>(N, vector<vector<bool>>(N, vector<bool>(N+1, false)));

        // init
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                f[i][j][1] = s1[i]==s2[j];

        int i, j, k, w;
        // loop range
        for(k=2; k<=N; ++k){
            for(i=0; i<=N-k; ++i){
                for(j=0; j<=N-k; ++j){
                    f[i][j][k] = false;

                    // loop range
                    // T1~S1 && T2~S2
                    for(w=1; w<=k-1; ++w){
                        if(f[i][j][w] && f[i+w][j+w][k-w]){
                            f[i][j][k] = true;
                            break;
                        }
                    }

                    // T2~S1 && T1~S2
                    for(w=1; w<=k-1; ++w){
                        if(f[i][j+k-w][w] && f[i+w][j][k-w]){
                            f[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[0][0][N];
    
    }
};
```