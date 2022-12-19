我真的服了，O(n^3)算法，一模一样，python就TLE，c++就能过，下次出题能不能给python时间长点？
好点的OJ上都会给python放宽时限

```c++
//272 ms
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int M = matrix[0].size();
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (matrix[i][j] != 0 && i != 0)
                    matrix[i][j] += matrix[i-1][j];
        
        int Ans = 0;
        for (int i = 0; i < min(N, M); ++i)
            for (int j = i; j < N; ++j) {
                int last = 0;
                for (int k = 0; k < M; ++k) {
                    if (matrix[j][k] > i)
                        last += 1;
                    else
                        last = 0;
                    if (last > i)
                        Ans += 1;
                }
            }
        return Ans;
    }
};
```

```python
    # 一模一样，TLE了
class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        N = len(matrix)
        M = len(matrix[0])
        
        n = min(N, M)
        
        for i in range(N):
            for j in range(M):
                if matrix[i][j] != 0 and i != 0:
                    matrix[i][j] += matrix[i-1][j]
        
        Ans = 0
        for i in range(n):
            for j in range(i, N):
                last = 0
                for k in range(M):
                    if matrix[j][k] > i:
                        last += 1
                    else:
                        last = 0
                    if last > i:
                        Ans += 1
        return Ans
```