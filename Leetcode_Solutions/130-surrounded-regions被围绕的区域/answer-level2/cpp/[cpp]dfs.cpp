思路:先去除所有与边界'O'相连的'O'，然后再转换中间符合要求的'O'
```cpp
class Solution {
public:
    int h,w=0,mode=0;
    void solve(vector<vector<char>>& board) {
        int i,j;
        h=board.size();if(h>0)w=board[0].size();
        vector<vector<int>>visit(h,vector<int>(w,0));
        for(i=0;i<w;++i)if(!visit[0][i]&&board[0][i]=='O')dfs(0,i,board,visit);//去除第一行
        for(i=0;i<h;++i)if(!visit[i][0]&&board[i][0]=='O')dfs(i,0,board,visit);//去除最后一行
        for(i=0;i<w;++i)if(!visit[h-1][i]&&board[h-1][i]=='O')dfs(h-1,i,board,visit);//去除第一列
        for(i=0;i<h;++i)if(!visit[i][w-1]&&board[i][w-1]=='O')dfs(i,w-1,board,visit);//去除最后一列
        mode=1;
        for(i=1;i<h-1;++i){//转换
            for(j=1;j<w-1;++j)
                if(!visit[i][j]&&board[i][j]=='O')dfs(i,j,board,visit);
        }
    }
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<int>>& visit){
        int a[4]={1,-1,0,0},b[4]={0,0,1,-1},i;
        if(mode==1)board[x][y]='X';visit[x][y]=1;
        for(i=0;i<4;++i){
            if(x+a[i]>=h-1||x+a[i]<=0||y+b[i]>=w-1||y+b[i]<=0)continue;//边界跳过
            if(!visit[x+a[i]][y+b[i]]&&board[x+a[i]][y+b[i]]=='O')dfs(x+a[i],y+b[i],board,visit);
        }
    }
};
```