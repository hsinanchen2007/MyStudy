### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    bool IsIndex(int i,int j,vector<vector<char>>& board)
    {
        return (i>=0)&&(i<board.size())&&(j>=0)&&(j<board[0].size());
    }
    bool num(int i,int j,vector<vector<char>>& board)
    {
        return board[i][j]>='1'&&board[i][j]<='8';
    }
    int find_mine(int i,int j,vector<vector<char>>& board)
    {
        int counter=0;
         for(int m=0;m<8;m++)
        {
            int col=i+dir[m][0];
            int raw=j+dir[m][1];
            if(IsIndex(col,raw,board))
            {
              if(board[col][raw]=='M')
                  counter++;
            }
        }
        return counter;
    }
    void DFS(vector<vector<char>>& result,int i,int j,vector<vector<char>>& board,vector<vector<int>> map)
    {
        if(IsIndex(i,j,board)==false||map[i][j]==1||board[i][j]!='E'||result[i][j]!='E')
            return;
      //  cout<<i<<" "<<j<<endl;
        map[i][j]=1;
        int cnt=find_mine(i,j,board);  //找出周围的地雷
        if(cnt)
        {
            char a=cnt+'0';
            result[i][j]=a;
            return;
        }
         result[i][j]='B';
        for(int m=0;m<8;m++)
        {
            int col=i+dir[m][0];
            int raw=j+dir[m][1];
            DFS(result,col,raw,board,map);
        }
        
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            vector<vector<char>> result(board.size(),vector<char>(board[0].size(),'0'));
             vector<vector<int>> map(board.size(),vector<int>(board[0].size(),0));
             for(int i=0;i<board.size();i++)
             {
                 for(int j=0;j<board[0].size();j++)
                    result[i][j]=board[i][j];
             }
             int x=click[0]; int y=click[1];
             if(result[x][y]=='M')
             {
                 result[x][y]='X';
             }
             else
                 DFS(result,x,y,board,map);
             return result;
    }
};
```