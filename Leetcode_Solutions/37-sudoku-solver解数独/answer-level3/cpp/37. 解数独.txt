### 解题思路
操作有点骚~~

主要思想就是回溯法。在回溯的过程中，剪去不满足条件的分枝以提高效率。

![image.png](https://pic.leetcode-cn.com/3d0d4de5efd00bf365397dee54a75a0f66c7a1f00307c73633872a0a0384349c-image.png)



### 代码

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //调用算法
        myfunc(board, 0, 0);
    }

    bool myfunc(vector<vector<char>>& board, int r, int c){
        //查找空格
        for(int i = r; i < 9; i++){
            for(int j = (i == r ? c : 0); j < 9; j++){
                if(board[i][j] == '.'){
                    r = i;
                    c = j;
                    goto dg;
                }
            }
        }

        return true;

        dg:

        for(int i = 1; i <= 9; i++){
            char ch = 48 + i;   //对于每个字符，判断是否可行
            //判断横向是否冲突
            for(int j = 0; j < 9; j++){
                if(board[r][j] == ch){
                    goto ctn;
                }
            }

            //判断纵向是否冲突
            for(int j = 0; j < 9; j++){
                if(board[j][c] == ch){
                    goto ctn;
                }
            }

            //判断9宫格内是否冲突
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    int startRow = r / 3;
                    int startCol = c / 3;
                    if(board[startRow * 3 + j][startCol * 3 + k] == ch){
                        goto ctn;
                    }
                }
            }

            board[r][c] = ch;
            if(myfunc(board, r, c)){
                return true;
            }
            board[r][c] = '.';

            ctn: continue;
        }

        return false;
    }
};
```