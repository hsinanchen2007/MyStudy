### 解题思路
1、学习到边界片段
2、学习到要用判断位，可以帮助原地实现
### 代码

```cpp
int around(vector<vector<int>>& board,int i,int j){
    int result=0;
    
    for(int m=-1;m<2;m++)
        for(int n=-1;n<2;n++){
            int row=i+m;
            int col=j+n;
            if(m!=0||n!=0)
                if((row>=0&&row<board.size())&&(col>=0&&col<board[0].size())&&(board[row][col]==1||board[row][col]==2))
                    result+=1;
        }
    return result;
}

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==1&&(around(board,i,j)<2||around(board,i,j)>3))
                    board[i][j]=2;//活的细胞死亡
                if(board[i][j]==0&&(around(board,i,j)==3))
                    board[i][j]=-1;//死的细胞存活
                
            }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==2)
                    board[i][j]=0;//活的细胞死亡
                if(board[i][j]==-1)
                    board[i][j]=1;//死的细胞存活
            }
    return;
    }
};
```