### 解题思路
好像没什么难点，对于每一个非空元素，检查其合法性即可。合法性检查有三种：行、列和框。
行列的检查比较简单，对于该行/列的元素是否有重合即可。
框的合法性略有点难度，需要根据row和col定位方框已经遍历方框中的其余元素，这里通过row-row%3,col-col%3很轻松地定位到方框的左上角元素，然后遍历一个3*3矩阵即可。
注意对比时要避开元素本身。

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.') continue;
                //检查行
                for(int i = 0; i < 9 && i != col; i++){
                    if(board[row][i] == board[row][col]){
                        return false;
                    }
                }
                //检查列
                for(int i = 0; i < 9 && i != row; i++){
                    if(board[i][col] == board[row][col]){
                        return false;
                    }
                }
                //检查框
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(i == row%3 && j == col%3) continue;
                        if(board[row-row%3+i][col-col%3+j] == board[row][col]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
```