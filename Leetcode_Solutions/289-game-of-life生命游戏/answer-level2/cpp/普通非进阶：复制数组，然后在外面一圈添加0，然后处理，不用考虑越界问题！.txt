### 解题思路
![1.PNG](https://pic.leetcode-cn.com/dcf91c34e4ba583ece7e3e9516552fee9749599b777903181f5280ce1f9b2521-1.PNG)


### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        vector<vector<int>> bigger_board(board.size()+2, vector<int> (board[0].size()+2) );
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                bigger_board[i+1][j+1] = board[i][j];
            }
        }
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                board[i][j] = is_alive(board[i][j], bigger_board, i+1, j+1);
            }
        }

    }

    int is_alive(int state, vector<vector<int>>& bigger_board, int i, int j) {
        int aliveNum = 0;
        for(int m=i-1; m<=i+1; m++)
        {
            for(int n=j-1; n<=j+1; n++)
            { 
                aliveNum += bigger_board[m][n]; 
            }
        }
        aliveNum -= bigger_board[i][j];
        if(state) 
        {
            if(aliveNum==2 || aliveNum==3) return 1;
        }
        else
        {
            if(aliveNum == 3)  return 1;
        }
        return 0;
    }
};
```