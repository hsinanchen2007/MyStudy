## 思路一：模拟法
一圈一圈打印，由外向内。
### 代码
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int times = (n + 1) / 2;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int c = 1;        
        int top = 0, down = n - 1, left = 0, right = n - 1;
        int i = 0, j = 0;
        for (int k = 0; k < times; ++k) {                        
            while (j <= right) {
                res[i][j] = c;
                ++j, ++c;
            }          
            ++i, --j;
            ++top;            
            while (i <= down) {
                res[i][j] = c;
                ++i, ++c;
            }          
            --i, --j;
            --right;
            while (j >= left) {
                res[i][j] = c;
                --j, ++c;
            }          
            ++j, --i;
            --down;
            while (i >= top) {
                res[i][j] = c;
                --i, ++c;
            }
            ++i, ++j;
            ++left;
        }
        return res;
    }
};
```

## 思路二：宏观控制
通过左上角和右下角两个点控制一圈输出。
**注意参数K为引用。**
### 代码
```c++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int mR = 0, mC = 0, nR = n - 1, nC = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1;
        while (mR <= nR && mC <= nC) {
            print(res, mR++, mC++, nR--, nC--, k);
        }
        return res;
    }
    
    void print(vector<vector<int>> &res, int a, int b, int c, int d, int &k) {
        if (a == c) {//只有一行
            for (int i = b; i <= d; ++i) {
                res[a][i] = k;
                ++k;
            } 
        } else if (b == d) {//只有一列
            for (int i = a; i <= c; ++i) {
                res[i][b] = k;
                ++k;
            }
        } else {
            int curR = a, curC = b;
            while (curC < d) {
                res[a][curC] = k;
                ++curC, ++k;
            }
            while (curR < c) {
                res[curR][d] = k;
                ++curR, ++k;
            }
            while (curC > b) {
                res[c][curC] = k;
                --curC, ++k;
            }
            while (curR > a) {
                res[curR][b] = k;
                --curR, ++k;
            }
        }
    }
};
```

