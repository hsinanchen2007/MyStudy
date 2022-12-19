### 解题思路

深度优先搜索 DFS套路
### 代码

```cpp
/*
首先，检查矩阵的四个边界。如果有一个元素是
'O'，改变它和它所有垂直方向相邻的'O'设置为'1'
最后，将所有的“1”改为“O”

举例：
    X X X X           X X X X             X X X X
    X X O X  ->       X X O X    ->       X X X X
    X O X X           X 1 X X             X O X X
    X O X X           X 1 X X             X O X X
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0){
            return;
        }
        int rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++){    //每行的两个左右边界是否为'O'进行深度优先搜索
            dfs(board,i,0);
            dfs(board,i,cols-1);
        }
        for(int j=1;j<cols-1;j++){  //除边界的每列的上下边界是否为'O'进行深度优先搜索
            dfs(board,0,j);
            dfs(board,rows-1,j);
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else{
                    board[i][j]='X';
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&board[i][j]=='O'){
            board[i][j]='1';
            //上下左右四个垂直方向与边界接触的O全部设置为1
            dfs(board,i-1,j);
            dfs(board,i+1,j);
            dfs(board,i,j-1);
            dfs(board,i,j+1);
        }
    }
};

```
![image.png](https://pic.leetcode-cn.com/304b339960ea3dc27ebdeb40f2b2c4e924a94bd9dca492a1feae6ae27d3b2d51-image.png)
