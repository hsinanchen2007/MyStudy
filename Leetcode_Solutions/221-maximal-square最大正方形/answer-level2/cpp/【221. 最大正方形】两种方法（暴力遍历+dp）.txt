## 思路一：暴力遍历
遍历数组中每一个点，边长s从1递增过程中，判断是否是正方形。在判断正方形过程中，通过预处理数组down[i][j]和right[i][j]记录包括当前位置下面和后面最多连续出现1的个数，这样由内向外扩展正方形大小，判断四条边是否都是1。如果不满足，则停止，判断当前节点最大边长是否大于已存的最大边长。
**注意：01为字符而不是数字**

### 代码
时间复杂度：O(row * col * min(row, col))
```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        //1. 设置预处理数组
        vector<vector<int>> down(row, vector<int>(col, 0));
        vector<vector<int>> right(row, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < col; ++j) {                
                if (i == row - 1) {
                    down[i][j] = matrix[i][j] - '0';
                } else {                    
                    down[i][j] = matrix[i][j] == '1' ? down[i+1][j] + 1 : 0;                    
                }                
            }
        }
        for (int j = col - 1; j >= 0; --j) {
            for (int i = 0; i < row; ++i) {
                if (j == col - 1) {
                    right[i][j] = matrix[i][j] - '0';
                } else {
                    right[i][j] = matrix[i][j] == '1' ? right[i][j+1] + 1 : 0;    
                }
                
            }
        }
        //2. 遍历数组每一个点
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int tmp = 0;
                for (int s = 1; s <= min(row-i, col-j); ++s) {                    
                    if (down[i][j] >= s && right[i][j] >= s && right[i+s-1][j] >= s && down[i][j+s-1] >= s) {
                        tmp = s;
                    } else {
                        break;
                    }
                }
                if (tmp > res) {
                    res = tmp;
                }
            }
        }
        return res * res;
    }
};
```

## 思路二：动态规划
![image.png](https://pic.leetcode-cn.com/2cd7f2a053f765726acfc8d78a4b513223d8f86b94275ae366a202c59f6622ce-image.png)
设置二维dp表，表示以[i,j]位置为右下角的最大正方形边长。如果当前位置为 1 ，则dp[i][j]值取决于dp[i-1][j],dp[i-1][j-1]和dp[i][j-1]的最小值。

### 代码
时间复杂度：O(row*col)
```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));        
        int maxLen = 0;
        for (int i = 0; i < row; ++i) {            
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;    
                maxLen = 1;
            }           
        }
        for (int j = 0; j < col; ++j) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                maxLen = 1;
            }
        }
        
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                }
            }
        }
        return maxLen * maxLen;
    }
};
```

