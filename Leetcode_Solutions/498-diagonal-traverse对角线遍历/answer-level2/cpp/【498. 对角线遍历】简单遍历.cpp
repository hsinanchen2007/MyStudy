## 思路一：直接遍历
**注意：两个特列，左下角和右上角，先判断大于等于越界范围，再判断小于0越界范围，**
### 代码
```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0, d = 1;
        vector<int> res(m * n);
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[r][c];
            r -= d;
            c += d;
            //先判断大于等于在判断小于
            if (c >= n) { c = n - 1, r += 2, d = -d;}
            if (r >= m) { r = m - 1, c += 2, d = -d;}   
            if (r < 0) { r = 0, d = -d;}
            if (c < 0) { c = 0, d = -d;}                   
        }
        return res;      
    }
};
```
#### 另一种写法
```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), r = 0, c = 0;
        vector<int> res(m * n);
        for (int i = 0; i < m * n; ++i) {
            res[i] = matrix[r][c];
            if ((r + c) % 2 == 0) { //moving up            
                if (c == n - 1) {
                    ++r;
                } else if (r == 0) {
                    ++c;
                } else {
                    --r, ++c;
                }
            } else { //moving down
                if (r == m - 1) {
                    ++c;
                } else if (c == 0) {
                    ++r;
                } else {
                    ++r, --c;
                }
            }
        }
        return res;      
    }
};
```

