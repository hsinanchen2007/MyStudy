### 解题思路
可以转换为背包问题处理, $f[i][j][k]$表示前i个串中能有多少被$j$个0和$k$个1组成

### 代码

```java []
class Solution {
    public int findMaxForm(String[] A, int M, int N) {
        // f[i][j][k]: 前i个01串最多能有多少个被j个0和k个1组成
        // 设置Si中有ai个0和bi个1
        // 转移方程
        // f[i][j][k] = max(f[i-1][j][k], f[i-1][j-ai-1][k-bi-1]+1 | j>=ai-1 AND k>=bi-1)
        // 边界条件
        // f[0][0~m][0~n]=0

        int T = A.length;
        int [][][]f = new int[T+1][M+1][N+1];
        // 记录0和1的数量
        int a0, a1;

        // init
        // 前0个字符串无法用0个1组成
        for(int j=0; j<=M; ++j)
            for(int k=0; k<=N; ++k)
                f[0][j][k] = 0;
        
        for(int i=1; i<=T; ++i){
            a0=a1=0;
            // 计算A[0]...A[i-1]中使用了多少0和1
            for(int j=0; j<A[i-1].length(); ++j){
                if(A[i-1].charAt(j)=='0'){
                    ++a0;
                }else{
                    ++a1;
                }
            }

            for(int j=0; j<=M; ++j){
                for(int k=0; k<=N; ++k){
                    f[i][j][k] = f[i-1][j][k];
                    if(j>=a0 && k>=a1)
                        f[i][j][k] = Math.max(f[i][j][k], f[i-1][j-a0][k-a1]+1);
                }
            }

        }

        return f[T][M][N];
    }
}
```
```python []
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        T, M, N = len(strs), m, n
        # 使用滚动数组优化
        now, old, a0, a1 = 0, 1, 0, 0
        # f[i][j][k]: 前i个序列最多使用了j个0和k个1
        f = [[[0 for _ in range(N+1)] for _ in range(M+1)] for _ in range(2)]
        for i in range(M+1):
            for j in range(N+1):
                f[now][i][j] = 0

        for i in range(1, T+1):
            now, old = old, now
            a0, a1 = 0, 0
            for j in range(len(strs[i-1])):
                if strs[i-1][j] == '0':
                    a0+=1
                else:
                    a1+=1
        # 方程:f[now][j][k] = max(f[old][j][k], f[old][j-a0][k-a1]+1)
            for j in range(M+1):
                for k in range(N+1):
                    f[now][j][k] = f[old][j][k]
                    if j>=a0 and k>=a1:
                        f[now][j][k] = max(f[now][j][k], f[old][j-a0][k-a1]+1)
        return f[now][M][N]

```
```c++ []
class Solution {
public:
    int findMaxForm(vector<string>& A, int M, int N) {
        // 可以使用滚动数组优化, 空间复杂度为O(MN)
        int T = A.size();
        // 状态: f[2][j][k] 表示A[0..i-1]中, 有j个0个k个1组成
        int now = 0, old = 1, a0, a1;

        vector<vector<vector<int>>> f = vector<vector<vector<int>>>(2, vector<vector<int>>(M+1, vector<int>(N+1, 0)));
        // init
        for(int i=0; i<=M; ++i)
            for(int j=0; j<=N; ++j)
                f[now][i][j] = 0;

        // 方程: f[now][j][k] = max(f[old][j][k], f[old][j-a0][k-a1]+1)
        for(int i=1; i<=T; ++i){
            old = now;
            now = 1-now;
            a0 = a1= 0;
            for(int j=0; j<A[i-1].size(); ++j){
                if(A[i-1][j]=='0')
                    ++a0;
                else
                    ++a1;
            }

            // 状态转移
            for(int j=0; j<=M; ++j){
                for(int k=0; k<=N; ++k){
                    f[now][j][k] = f[old][j][k];
                    if(j>=a0 && k>=a1)
                        f[now][j][k] = max(f[now][j][k], f[old][j-a0][k-a1]+1);
                }
            }
        }

        return f[now][M][N];    
    }
};
```