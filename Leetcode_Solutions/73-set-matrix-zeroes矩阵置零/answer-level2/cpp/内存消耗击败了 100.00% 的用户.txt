### 解题思路
不能用多余的空间，那么就创造两个vector<int> zero_i, zero_j;分别存储元素为0的坐标x与坐标y
然后再遍历即可

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        vector<int> zero_i, zero_j;
        int row_num = matrix.size(), col_num = matrix[0].size(); 
        for(int i = 0; i < row_num; ++i){
            for(int j = 0; j < col_num; ++j){
                if(matrix[i][j] == 0){
                    zero_i.push_back(i); zero_j.push_back(j);
                }
            }
        }
        int k = 0;
        for(int i = 0; i < row_num; ++i){
            for(int j = 0; j < col_num; ++j){
                if(k < zero_i.size() && i == zero_i[k] && j == zero_j[k]){
                    setColRowZero(i, j, matrix); 
                    ++k;
                }
            }
        }
    }

    void setColRowZero(int i, int j, vector<vector<int>>& matrix){
        int row_num = matrix.size(), col_num = matrix[0].size();
        for(int k = 0; k < col_num; ++k){
            matrix[i][k] = 0;
        }
        for(int k = 0; k < row_num; ++k){
            matrix[k][j] = 0;
        }
    }
};
```

### 结果
执行用时 : 28 ms , 在所有 C++ 提交中击败了 20.67% 的用户 
内存消耗 : 9.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户