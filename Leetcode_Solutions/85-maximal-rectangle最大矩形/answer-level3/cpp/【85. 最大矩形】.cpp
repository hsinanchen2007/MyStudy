## 思路一：暴力法

### 代码
时间复杂度：O(row * col * col)
```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        vector<int> height(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                    continue;
                }                
                ++height[j];
                int minH = height[j];
                for (int k = j; k >= 0; --k) {
                    minH = min(minH, height[k]);
                    res = max(res, minH * (j - k + 1));
                }             
            }
        }
        return res;
    }
};
```

## 思路二：柱状图-栈
基于84题状态图求矩形，遍历每行求出状态图高度。
### 代码
```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        vector<vector<int>> height(row, vector<int>(col, 0));
        //初始化第一行高度
        for (int j = 0; j < col; ++j) {
            height[0][j] = matrix[0][j] - '0';
        }
        res = max(res, helper(height[0]));
        //遍历每行求出高度
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    height[i][j] = height[i-1][j] + 1;
                } else {
                    height[i][j] = 0;
                }
            }
            res = max(res, helper(height[i]));
        }
        return res;
    }
    
    int helper(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        stack<int> st;
        height.push_back(0);
        int size = height.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                int val = st.top();
                st.pop();
                res = max(res, height[val] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
```
#### 简化代码
**height大小为col+1**，因为只有当最后一列小于等于前一列高度才会计算矩形面积，所以为了避免最后一列为最高值，在最后一列后添加一个0列，这样就一定会计算前面矩形面积。
```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        vector<int> height(col + 1);
        for (int i = 0; i < row; ++i) {
            stack<int> st;
            for (int j = 0; j < col + 1; ++j) {
                if (j < col) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;    
                }
                while (!st.empty() && height[st.top()] >= height[j]) {
                    int val = st.top();
                    st.pop();
                    res = max(res, height[val] * (st.empty() ? j : (j - st.top() - 1)));
                }
                st.push(j);                
            }            
        }
        return res;
    }    
};
```


