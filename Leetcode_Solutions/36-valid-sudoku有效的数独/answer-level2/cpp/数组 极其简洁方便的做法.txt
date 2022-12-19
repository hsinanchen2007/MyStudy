### 解题思路

![image.png](https://pic.leetcode-cn.com/c37a5192bafb2a0a9da1353eec0262b91d8c6578404db23e9905da952a6d0708-image.png)

直接用数组就行

### 代码

```cpp
class Solution {
public:
    int row[9][9], col[9][9], cell[3][3][9];
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
            {
                char c = board[i][j];
                if(c != '.')
                {
                    row[i][c - '1'] ++;
                    col[j][c - '1'] ++;
                    cell[i / 3][j / 3][c - '1'] ++;
                    if(row[i][c - '1'] > 1 || col[j][c - '1'] > 1 || cell[i / 3][j / 3][c - '1'] > 1)
                        return false;
                }

            }
        return true;
    }
};
```