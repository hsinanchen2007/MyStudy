# 1. 动态规划常用的解题步骤

- 第一步：**确定子问题**：在这一步重点是分析那些变量是随着问题规模的变小而变小的， 那些变量与问题的规模无关。
- 第二步：**确定状态**：根据上面找到的子问题来给你分割的子问题限定状态
- 第三步：**推导出状态转移方程**：这里要注意你的状态转移方程是不是满足所有的条件， 注意不要遗漏。
- 第四步：**确定边界条件**：先根据题目的限制条件来确定题目中给出的边界条件是否能直接推导出， 如果不行也可以尝试从边界条件反推;
- 第五步：**确定实现方式**：这个依照个人习惯 就像是01背包的两层for循环的顺序
- 第六步：**确定优化方法**：很多时候你会发现走到这里步的时候你需要返回第1步重来。首先考虑降维问题（优化内存）， 优先队列、四边形不等式（优化时间）等等
# 2. 思路
## 第一步：确定子问题
```
dp(r,c),第r层，第c列开始的最小路径和，数组A不变。
```
## 第二步：确定状态
r为最后一层，r不为最后一层。当r为最后一层时，dp(r,c) = A[r][c];当r不为最后一层时，dp(r,c)等于A[r][c]+下一层的子问题的解的最小值。
## 第三步：推导状态转移方程
```
在不考虑边界的情况下
dp(r,c) = A[r][c] + min(dp[r+1][c-1],dp[r+1][c],dp[r+1][c+1])
```
## 第四步：确定边界条件
当r为最后一层，dp(r,c) = A[r][c]。
## 确定实现方式
1. **自底向上**
    两层循环
2. **自顶向下（严格来说是分治的思想，动态规划也是分治的一种）**
    递归
## 确定优化方法

# 3. 实现
## 3.1 自底向上
```c++
    int min_value1(vector<vector<int>>& A){
        int rows,columns;
        rows = columns = A.size();
        for(int r=rows-2; r>=0; r--){
            for(int c=0; c<columns; c++){
                int best = A[r+1][c];
                if(c>0) best = min(best, A[r+1][c-1]);
                if(c<rows-1) best = min(best, A[r+1][c+1]);
                A[r][c] += best;
            }
        }
        int value = INT_MAX;
        for(int e : A[0])
            value = min(value, e);
        return value;
    }
```
## 3.2 自顶向下
```c++
    int min_value2(vector<vector<int>>& A, const int N, int row, int column){
        if(row == N-1){
            return A[row][column];
        }else{
            int next_best = min_value2(A, N, row+1, column);
            if(column > 0) next_best = min(next_best, min_value2(A, N, row+1, column-1));
            if(column < N-1) next_best = min(next_best, min_value2(A, N, row+1, column+1));
            return A[row][column]+next_best;
        }
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int N = A.size();
        int value = INT_MAX;
        for(int c=0; c < N; c++){
            value = min(value, min_value2(A,N,0,c));
        }
        return value;
    }
```