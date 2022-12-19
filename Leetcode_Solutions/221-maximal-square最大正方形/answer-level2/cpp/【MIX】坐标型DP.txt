### 解题思路
f[i][j]表示以(i, j)为**右下角**的最大全1正方形的边长

### 代码

```java []
class Solution {
    public int maximalSquare(char[][] matrix) {
        // f[i][j]以(i, j)为右下角的最大全1正方形的边长
        // 方程:
        // f[i][j] = 0, if(i, j)=0
        // f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1])+1

        if(matrix == null || matrix.length==0 || matrix[0].length==0)
            return 0;

        int N = matrix.length;
        int M = matrix[0].length;

        int[][] f = new int[N+1][M+1];
        f[0][0] = 0;
        int maxL = 0;
        for(int i=1; i<=N; ++i){
            for(int j=1; j<=M; ++j){
                if(matrix[i-1][j-1] == '0')
                    f[i][j] = 0;
                else if(matrix[i-1][j-1]=='1')
                    f[i][j] = Math.min(f[i-1][j], Math.min(f[i][j-1], f[i-1][j-1]))+1;

                maxL = Math.max(maxL, f[i][j]);
            }
        }

        return maxL*maxL;
    }
}
```
```python []
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if matrix == None or len(matrix)==0 or len(matrix[0])==0:
            return 0

        R, C = len(matrix), len(matrix[0])

        f = [[0 for _ in range(C+1)] for _ in range(R+1)]

        maxL = 0
        for i in range(1, R+1):
            for j in range(1, C+1):
                if matrix[i-1][j-1] == '0':
                    f[i][j] = 0

                else:
                    f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1])+1

                maxL = max(maxL, f[i][j])

        return maxL**2
```
```c++ []
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int R = matrix.size();
        if(R == 0)
            return 0;
        int C = matrix[0].size();
        if(C == 0)
            return 0;

        auto f = vector<vector<int>>(R+1, vector<int>(C+1, 0));
        int maxL = 0;
        f[0][0] = 0;
        for(int i=1; i<=R; ++i){
            for(int j=1; j<=C; ++j){
                if(matrix[i-1][j-1] == '0')
                    f[i][j] = 0;
                else if(matrix[i-1][j-1]=='1')
                    f[i][j] = min(f[i-1][j], min(f[i][j-1], f[i-1][j-1]))+1;
                
                maxL = max(maxL, f[i][j]);
            }
        }

        return maxL*maxL;
    }
};
```