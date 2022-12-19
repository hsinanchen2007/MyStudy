## 思路一：自顶向下
**注意：下一层相邻节点为位置**

### 代码
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();       
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i-1][j];
                } else if (j == i) {
                    triangle[i][j] += triangle[i-1][j-1];
                } else {
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                }
            }    
        }

        //在最后一层中遍历寻找最小值
        int res = triangle[row-1][0];
        for (int s : triangle[row-1]) {
            res = min(s, res);
        }
        return res;
    }
};
```

## 思路二：自底向上

### 代码
```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
```

### 另一种写法
不修改原始数组，利用最后一行作为DP数组，自底向上更新DP数组。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for (int i = (int)triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
```
