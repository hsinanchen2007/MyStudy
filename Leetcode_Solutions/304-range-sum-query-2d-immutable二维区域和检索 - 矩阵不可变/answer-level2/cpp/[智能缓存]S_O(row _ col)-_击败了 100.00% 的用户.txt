### 解题思路
![304_rangeSum2D.png](https://pic.leetcode-cn.com/8a2ad8d3ffa14bb6815e4dcdc37fdd0ec709d17e48ae769635e540ddc5873779-304_rangeSum2D.png)
构造区域和缓存的时候，最清晰的框架是不要去check edge：
- 多构造1行1列；
- 检索的时候在输入上+1
这样就可以实现缓存和检索区域的mapping了。

切割区域利用缓存求和的时候注意锁定边界，比如说：
- 构造缓存的时候，是在利用已知和切割未知和，加一个右下角（默认行列从小到大递增，方向就是左上->右下），一格一格初始化，所以边界差为1；
- 但是检索的时候是输入决定区域范围，所以这里才是边界差的一般情况，根据构造的扫描方向，area = big_area - row_child_area - col_child_area + row&col_child_area

不过我不明白为什么「构造区域和缓存，检索子区域和」的法子跑得这么差
难道是OJ的问题么？提交了两次没改代码第二次居然比第一次少用了1/3时间。。。

### 代码

```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rw = matrix.size();
        cl = rw ?  matrix[0].size() : 0;
        sumMatrix = vector<vector<int>>(rw + 1, vector<int> (cl + 1, 0));
        for (int i = 1; i < rw + 1; ++i){
            for (int j = 1; j < cl + 1; ++j){
                sumMatrix[i][j] = matrix[i - 1][j - 1] + 
                sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {        
        return sumMatrix[row2 + 1][col2 + 1] - sumMatrix[row1][col2 + 1] - sumMatrix[row2 + 1][col1] + sumMatrix[row1][col1];
    }
private:
    int rw, cl;
    vector<vector<int>> sumMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```