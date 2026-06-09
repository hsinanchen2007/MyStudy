## 思路
设定上下左右四个边界，按照从左->右，上->下，右->左，下->上顺序遍历，每次遍历完重新设定边界，用count记录剩余元素个数，如果为0跳出循环。
**注意：开始需要判断矩阵是否为空**
### 代码
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int row = matrix.size(), col = matrix[0].size();
        int count = row*col;
        int L = 0, R = col - 1;
        int top = 0, down = row - 1;
        int i = 0, j = 0;
        while (count) {
            while (count > 0 && j <= R) {
                res.push_back(matrix[i][j]);
                ++j;
                --count;
            }
            --j;
            ++top;
            ++i;
            while (count > 0 && i <= down) {
                res.push_back(matrix[i][j]);
                ++i;
                --count;
            }
            --i;
            --R;
            --j;
            while (count > 0 && j >= L) {
                res.push_back(matrix[i][j]);
                --j;
                --count;
            }
            ++j;
            --down;
            --i;
            while (count > 0 && i >= top) {
                res.push_back(matrix[i][j]);
                --i;
                --count;
            }
            ++i;
            ++L;
            ++j;
        }
        return res;
    }
};
```
### 另一种方法
在遍历过程中，判断是否越出边界，如果越出则跳出循环。
```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int row = matrix.size(), col = matrix[0].size();        
        int L = 0, R = col - 1;
        int top = 0, down = row - 1;
        while (true) {
            for (int j = L; j <= R; ++j) {
                res.push_back(matrix[top][j]);
            }
            if (++top > down) {
                break;
            }
            for (int i = top; i <= down; ++i) {
                res.push_back(matrix[i][R]);                
            }
            if (--R < L) {
                break;
            }
            for (int j = R; j >= L; --j) {
                res.push_back(matrix[down][j]);                
            }
            if (--down < top) {
                break;
            }
            for (int i = down; i >= top; --i) {
                res.push_back(matrix[i][L]);                
            }
            if (++L > R) {
                break;
            }            
        }       
        return res;
    }
};
```

