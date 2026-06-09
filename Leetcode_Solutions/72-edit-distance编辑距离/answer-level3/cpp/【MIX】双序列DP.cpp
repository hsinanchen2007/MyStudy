### 解题思路
1. 4中可能, 替换/删除/添加/不变
2. 注意检查边界条件, 时间复杂度$O(NM)$, 空间复杂度$O(MN)$

### 代码

```java []
class Solution {
    public int minDistance(String word1, String word2) {
        // 状态: f[i][j]: A[0..i-1]和B[0..j-1]的最小编辑距离
        // 方程: f[i][j] = min{f[i][j-1]+1, f[i-1][j-1]+1, f[i-1][j]+1, f[i-1][j-1] | A[i-1]=B[j-1]}
        // 边界: f[0][j] = j, f[i][0] = i
        
        int M = word1.length();
        int N = word2.length();

        char[] s1 = word1.toCharArray();
        char[] s2 = word2.toCharArray();

        int [][] f = new int[M+1][N+1];

        for(int i=0; i<=M; ++i)
            for(int j=0; j<=N; ++j){
                if(i==0)
                    f[i][j] = j;
                else if(j==0)
                    f[i][j] = i;
                else
                    // 删除 & 替换 & 添加
                    f[i][j] = Math.min(f[i][j-1]+1, Math.min(f[i-1][j-1]+1, f[i-1][j]+1));
                    // 相同
                    if(i>0 && j>0 && s1[i-1] == s2[j-1])
                        f[i][j] = Math.min(f[i][j], f[i-1][j-1]);

            }

        return f[M][N];
    }
}
```
```python []
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        N, M = len(word1), len(word2)
        if N == 0 and M == 0:
            return 0
        
        # f[i][j]
        f = [[0 for _ in range(M+1)] for _ in range(N+1)]

        for i in range(N+1):
            for j in range(M+1):
                if i==0:
                    f[i][j] = j
                elif j==0:
                    f[i][j] = i
                else:
                    # status transfer function
                    f[i][j] = min(f[i-1][j]+1, min(f[i-1][j-1]+1, f[i][j-1]+1))
                    if i>0 and j>0 and word1[i-1] == word2[j-1]:
                        f[i][j] = min(f[i][j], f[i-1][j-1])

        return f[N][M]
```
```c++ []
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        if(N==0 && M==0)
            return 0;

        // 状态: f[i][j], s1[0..i-1]->s2[0..j-1]最少操作次数
        vector<vector<int>> f = vector<vector<int>>(N+1, vector<int>(M+1, 0));
        // 插入 & 替换 & 删除
        // 方程: f[i][j] = min(f[i-1][j]+1, f[i-1][j-1]+1, f[i][j-1]+1, f[i-1][j-1]|s1[i-1]==s2[j-1])
        // 边界: f[0][j] = j; f[i][0] = i;
        for(int i=0; i<=N; ++i)
            for(int j=0; j<=M; ++j){
                if(i==0)
                    f[i][j] = j;
                else if(j == 0)
                    f[i][j] = i;
                else
                    f[i][j] = min(f[i-1][j]+1, min(f[i-1][j-1]+1, f[i][j-1]+1));
                    if(i>0 && j>0 && word1[i-1] == word2[j-1])
                        f[i][j] = min(f[i][j], f[i-1][j-1]);
            }
        return f[N][M];
    }
};
```