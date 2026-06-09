### 解题思路
1. 先沿着副对角线翻转,$(i, j)~(N-1-j, N-1-i)$, 再沿着水平中线翻转$(i, j)~(N-1-i, j)$, 时间复杂度$O(N^2)$, 空间复杂度$O(1)$.
2. 先沿着水平中线翻转, 再沿着主对角线翻转$(i,j)~(j,i)$

### 代码

```java []
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        // 先以水平中线翻转, 再以主对角线翻转
        for(int i=0; i<N/2; ++i){
            for(int j=0; j<N; ++j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N-i-1][j];
                matrix[N-i-1][j] = temp;
            }
        }

        for(int i=0; i<N; ++i){
            for(int j=i; j<N; ++j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return;
    }
}
```
```python []
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        N = len(matrix)

        for i in range(N//2):
            for j in range(N):
                matrix[i][j], matrix[N-1-i][j] =  matrix[N-1-i][j], matrix[i][j]

        for i in range(N):
            for j in range(i, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```
```c++ []
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 翻转方法：先沿着副对角线翻转一次, 再沿着水平中线翻转一次
        const int N = matrix.size();
        
        // 沿着副对角线翻转, 坐标关系满足i-j+N=N, N-1, ... 1
        for(int i=0; i<N; ++i){
            for(int j=0; j<N-i; ++j){
                swap(matrix[i][j], matrix[N-j-1][N-i-1]);
            }
        }

        // 沿着水平中线翻转
        for(int i=0; i<N/2; ++i){
            for(int j=0; j<N; ++j){
                swap(matrix[i][j], matrix[N-1-i][j]);
            }
        }

        return;
    }
};
```