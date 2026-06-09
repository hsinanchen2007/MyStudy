```
 5  1  9 11                 15 14 12 16
 2  4  8 10                 13  3  6  7
------------   =水平翻转=>   ------------
13  3  6  7                  2  4  8 10
15 14 12 16                  5  1  9 11

15 14 12 16                   15 13  2  5
13  3  6  7   =主对角线翻转=>   14  3  4  1
 2  4  8 10                   12  6  8  9
 5  1  9 11                   16  7 10 11

```


```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for(int row = 0; row < n/2; row++){
            for(int col = 0; col < n; col++){
                swap(matrix[row][col], matrix[n - row - 1][col]);           
            }
        }
        // 主对角线翻转
        for(int row = 0; row < n; row++){
            for(int col = 0; col < row; col++){
                swap(matrix[row][col], matrix[col][row]);           
            }
        }
    }
};
```
