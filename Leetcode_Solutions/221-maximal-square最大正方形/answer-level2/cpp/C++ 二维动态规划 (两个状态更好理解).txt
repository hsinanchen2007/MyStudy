### 解题思路
 动态规划

 1. 确定dp数组和状态
      (1) 输入为二维，因此一般情况下dp数组也是二维的
      (2) 对于某个由1组成的正方形，假设其右下角为(i,j),则必然有(i,j)向左的连续'1'的数目>=边长，(i,j)向上的连续'1'的数目>=边长
            因此考虑使用两个状态来进行记录(struct 或 pair)
 2. base case
      `dp[0][0] = (matrix[0][0]=='1')?1:0;`
 3. 状态转移方程
      `dp[i][j]`的状态不仅与`dp[i-1][j] dp[i][j-1]`有关，还与`dp[i-1][j-1]`有关，
      即
```
        dp[i][i].row_nums = min(dp[i-1][j].row_nums, dp[i-1][j-1].row_nums)+1;  
        dp[i][i].col_nums = min(dp[i-1][j].col_nums, dp[i-1][j-1].col_nums)+1;
```
 4. 最后遍历数组，求最大正方形面积

 为便于计算，dp数组行数为rows+1, 列数为cols+1
            `dp[0][...]=0, dp[...][0]=0`
            对dp数组的遍历从1~rows  1~cols

### 代码

```cpp
struct Node{
    int row_nums;
    int col_nums;
    Node():row_nums(0), col_nums(0){}
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        // 1. 确定dp数组和状态
        vector<vector<Node>> dp(rows+1, vector<Node>(cols+1));
        // 2. base case(dp[0][...]=0 & dp[...][0]=0)
        // 3. 状态转移方程
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j].row_nums = min(dp[i-1][j].row_nums, dp[i-1][j-1].row_nums)+1;
                    dp[i][j].col_nums = min(dp[i][j-1].col_nums, dp[i-1][j-1].col_nums)+1;
                }
            }
        }
        // 4. 遍历dp计算最大正方形
        int max_size = 0;
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                int edge = min(dp[i][j].row_nums, dp[i][j].col_nums);
                max_size = max(max_size, edge*edge);
            }
        }
        return max_size;
    }
};
```