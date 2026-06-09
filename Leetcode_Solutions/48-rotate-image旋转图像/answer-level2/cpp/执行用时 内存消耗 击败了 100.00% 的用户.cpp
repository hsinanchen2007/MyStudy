### 解题思路
顺时针旋转90° = 沿着X轴翻转 + 沿着对角翻转


### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        flipWithX(matrix);
        flipWithDiag(matrix);
    }

    void flipWithX(vector<vector<int>>& matrix){
        int width = matrix[0].size(), height = matrix.size();
        for(int i = 0; i < height/2; ++i){
            for(int j = 0; j < width; ++j){
                swap(matrix, i, j, height-1-i, j);
            }
        }
    }

    void flipWithDiag(vector<vector<int>>& matrix){
        int width = matrix[0].size(), height = matrix.size();
        for(int i = 0; i < height; ++i){
            for(int j = i+1; j < width; ++j){
                swap(matrix, i, j, j, i);
            }
        }
    }

    void swap(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2){
        int tmp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = tmp;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.7 MB , 在所有 C++ 提交中击败了 100.00% 的用户