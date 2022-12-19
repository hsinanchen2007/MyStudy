## 思路
螺旋矩阵按照一层一层的角度来看，每上下左右看作一轮。

+　首先算出总共多少轮，记作level
+ 每一level进行上下左右四次循环
+ 注意处理最后一层循环避免重复
难点在于四次循环的条件范围和最后一层的处理。
## 代码
### C++ 实现
> 执行用时 :0 ms, 在所有 C++ 提交中击败了
100.00%
的用户
>
> 内存消耗 :
8.5 MB
, 在所有 C++ 提交中击败了
83.07%
的用户
>
> 感觉像是LeetCode出错了，怎么可能这么高？
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        vector<int> a;
        int M = matrix.size();
        int N = matrix[0].size();
        int levels = M > N ? (N+1)/2:(M+1)/2;
        for (int i = 0; i < levels; i++){
            for (int j = i;j <= N - i - 1; j++)
                a.push_back(matrix[i][j]);
            for (int j = i + 1 ; j <= M - i - 1; j++)
                a.push_back(matrix[j][N - i - 1]);
            for (int j = N - i - 2; j >= i ; j--){
                if  (M - i -1 == i) break;
                a.push_back(matrix[M - i - 1][j]);
            }
            for (int j = M - i - 2; j > i ; j--){
                if  (N - i -1 == i) break;  
                a.push_back(matrix[j][i]);
            }
        }
        return a;
    }
};
```
### Python3 实现
```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        a = []
        M = len(matrix)
        N = len(matrix[0])
        levels = (N+1)//2 if M > N else (M+1)//2;
        for i in range(levels):
            for j in range(i,N - i):
                a.append(matrix[i][j])
            for j in range(i + 1,M - i):
                a.append(matrix[j][N - i - 1])
            for j in range(N-i-2,i-1,-1):
                if  M - i -1 == i:
                    break
                a.append(matrix[M - i - 1][j])
            for j in range(M-i-2,i,-1):
                if  N - i -1 == i:
                    break
                a.append(matrix[j][i])
        return a;
```