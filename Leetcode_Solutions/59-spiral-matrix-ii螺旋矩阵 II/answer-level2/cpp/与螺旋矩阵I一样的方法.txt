### 解题思路
与螺旋矩阵I一样的方法，详细可以看另外一个题解

### 代码

```cpp
class Solution {
public:
    long total_num_ = -1;
    long num_ = 1;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        total_num_ = n*n;
        initialMatrix(res, n);
        int row_num = n, col_num = n, row = 0, col = 0;
        while(num_ <= total_num_){
            lToR(res, row, col, col_num); --row_num; ++row;
            if(num_ > total_num_) break;
            uToD(res, row, col, row_num); --col_num; --col;
            if(num_ > total_num_) break;
            rToL(res, row, col, col_num); --row_num; --row;
            if(num_ > total_num_) break;
            dToU(res, row, col, row_num); --col_num; ++col;
        }
        return res;
    }
    void uToD(vector<vector<int>> &res, int &row, int &col, int len){
        bool flag = false;
        //cout << row << " " << col << " " << len << endl;
        for(int i = 0; i < len; ++i){
            //cout << num_ << endl;
            res[row][col] = num_; 
            ++num_; ++row;
            flag = true;
        }
        if(flag) {
            --row;
        }
    }

    void dToU(vector<vector<int>> &res, int &row, int &col, int len){
        bool flag = false;
        for(int i = 0; i < len; ++i){
            res[row][col] = num_; 
            ++num_; --row;
            flag = true;
        }
        if(flag) {
            ++row;
        }
    }

    void lToR(vector<vector<int>> &res, int &row, int &col, int len){
        bool flag = false;
        for(int i = 0; i < len; ++i){
            res[row][col] = num_; 
            ++num_; ++col;
            flag = true;
        }
        if(flag){
            --col;
        } 
    }

    void rToL(vector<vector<int>> &res, int &row, int &col, int len){
        bool flag = false;
        for(int i = 0; i < len; ++i){
            res[row][col] = num_; 
            ++num_; --col;
            flag = true;
        }
        if(flag) {
            ++col;
        }
    }

    void initialMatrix(vector<vector<int>> &res, int n){
        for(int i = 0; i < n; ++i){
            vector<int> tmp;
            for(int j = 0; j < n; ++j){
                tmp.push_back(0);
            }
            res.push_back(tmp);
        }
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 65.13% 的用户 
内存消耗 : 6.9 MB , 在所有 C++ 提交中击败了 100.00% 的用户