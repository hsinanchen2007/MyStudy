- dfs暴力做法

题目的标签是dp,想了良久不知这种做法是咋做的。

```cpp
class Solution
{
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int flag,p,q,n;
    vector<vector<bool>>vis;
    bool exist(vector<vector<char>>& board, string word){
        p=board.size(),q=board[0].size(),n=word.size();
        vis = vector<vector<bool>>(p,vector<bool>(q,0));
        for(int i=0; i<p; i++){
            for(int j=0; j<q; j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(dfs(board,word,0,i,j))return true;
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,string &word,int index,int x,int y){
        if(board[x][y]!= word[index])return false;
        if(index == n-1)return true;
        for(int k = 0; k<4; k++){
            int newX = x+dir[k][0];
            int newY = y+dir[k][1];
            if(newX<0 || newX>=p || newY<0 || newY>=q || vis[newX][newY])continue;
            vis[newX][newY]=1;
            if(dfs(board,word,index+1,newX,newY))return true;
            vis[newX][newY]=0;
        }
        return false;
    }
};
```