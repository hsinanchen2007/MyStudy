### 解题思路
回溯法应该是该类题型比较常见的思路了，主要是要理清思路，考虑清楚什么条件下进行回溯，回溯的过程是如何的。
这里我们对二维矩阵进行遍历，遍历到每一个空元素时，对其进行行列和方框检查，看看这个格子还剩下哪些合法元素可以放入。检查完毕后，按次序依次尝试每一个合法元素，填入后遍历下一个位置，直到整个矩阵被填满（找到答案），或者在某个位置发现没有任何合法元素可以放下了，这个时候就需要进行回溯。回溯的时候注意要不能直接return，因为我们在遍历过程的元素放入时对board进行了引用修改，回溯时必须要还原所作的修改，即把空格元素还原为空后，再进行回溯。
代码如下：

### 代码

```cpp
class Solution {
public:
    bool BackTrack(vector<vector<char>>& board, int row, int col){
        if(board[row][col] == '.'){
            bool legal[9] = {1,1,1,1,1,1,1,1,1}; //表示1-9是否可用，初始化为可用
            //检查行列
            for(int i = 0; i < 9; i++){
                if(board[row][i] != '.'){
                    legal[board[row][i] - '1'] = 0;
                }
                if(board[i][col] != '.'){
                    legal[board[i][col] - '1'] = 0;
                }
            }
            //检查框
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[row-row%3+i][col-col%3+j] != '.'){
                        legal[board[row-row%3+i][col-col%3+j] - '1'] = 0;
                    }
                }
            }
            //回溯法，尝试每一个合法元素
            for(int i = 0; i < 9; i++){
                if(!legal[i]) continue;
                board[row][col] = '1' + i; //填入一个合法元素

                int next_row, next_col;
                if(col != 8){       //列未到末尾，右移
                    next_row = row;
                    next_col = col + 1;
                }else if(row != 8){ //列到末尾，但行未到末尾，进入下一行
                    next_row = row + 1;
                    next_col = 0;
                }else{              //行列都到末尾，算法结束，返回true
                    return true;
                }

                if(BackTrack(board, next_row, next_col)){   //如果该元素走得通，则直接返回true
                    return true;
                }
            }
            //所有元素都走不通，还原该元素为‘.’后返回false
            board[row][col] = '.';
            return false;
        }else{
            int next_row, next_col;
            if(col != 8){       //列未到末尾，右移
                next_row = row;
                next_col = col + 1;
            }else if(row != 8){ //列到末尾，但行未到末尾，进入下一行
                next_row = row + 1;
                next_col = 0;
            }else{              //行列都到末尾，算法结束，返回true
                return true;
            }

            return BackTrack(board, next_row, next_col);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if(BackTrack(board, 0, 0)) return;
        return;
    }
};
```