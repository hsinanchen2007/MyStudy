### 解题思路
如果从左往右或者从右往左遍历，那么长度自减1
如果从上到下或者从下到上遍历，那么宽度自减1

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int x_len = matrix[0].size(), y_len = matrix.size();
        int x = 0, y = 0;
        while(res.size() < matrix[0].size() * matrix.size()){
            lToR(res, matrix, x, y, x_len); --y_len; ++x; 
            if(res.size() >= matrix[0].size() * matrix.size()) break;
            //cout << x << " " << y << " " << y_len << " " << endl;
            uToD(res, matrix, x, y, y_len); --x_len; --y;
            if(res.size() >= matrix[0].size() * matrix.size()) break;
            rToL(res, matrix, x, y, x_len); --y_len; --x;
            if(res.size() >= matrix[0].size() * matrix.size()) break;
            dToU(res, matrix, x, y, y_len); --x_len; ++y;
            //cout << x << " " << y << " " << x_len << " " << y_len << " " << endl;
        }
        return res;
    }

    void lToR(vector<int> &res, vector<vector<int>>& matrix, int &row, int &col, int x_len){
        bool flag = false;
        for(int i = 0; i < x_len; ++i){
            res.push_back(matrix[row][col]);
            ++col;
            flag = true;
        }
        if(flag) --col;
    }

    void rToL(vector<int> &res, vector<vector<int>>& matrix, int &row, int &col, int x_len){
        bool flag = false;
        for(int i = 0; i < x_len; ++i){
            res.push_back(matrix[row][col]);
            --col;
            flag = true;
        }
        if(flag) ++col;
    }

    void uToD(vector<int> &res, vector<vector<int>>& matrix, int &row, int &col, int y_len){
        bool flag = false;
        for(int i = 0; i < y_len; ++i){
            res.push_back(matrix[row][col]);
            ++row;
            flag = true;
        }
        if(flag) --row;
    }
    void dToU(vector<int> &res, vector<vector<int>>& matrix, int &row, int &col, int y_len){
        //cout << "dToU: " << row << ", " << col << " " << y_len << endl;
        bool flag = false;
        for(int i = 0; i < y_len; ++i){
            res.push_back(matrix[row][col]);
            --row;
            flag = true;
        }
        if(flag) ++row;
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 61.45% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户