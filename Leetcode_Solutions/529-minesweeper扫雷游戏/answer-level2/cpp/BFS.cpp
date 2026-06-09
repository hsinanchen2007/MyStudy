### 解题思路
此处撰写解题思路
BFS
### 代码

```cpp
class Solution {
public:
    struct node{
        int x;
        int y;
        node(int xx,int yy):x(xx),y(yy){}
    };
    int m,n;
    int a[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int visit[60][60]={false};
    bool judge(int x,int y,vector<vector<char>>& board){
        if(x<0||x>=m||y<0||y>=n){
            return false;    
        }
        if(visit[x][y]==true){
            return false;
        }
        return true;
    }
    int update(int x,int y,vector<vector<char>>& board){
        if(judge(x,y,board)==1){
        int ans=0;
        for(int i=0;i<8;++i){
            int xx=x+a[i][0];
            int yy=y+a[i][1];
            if(xx>=0&&xx<m&&yy>=0&&yy<n)
             if(board[xx][yy]=='M'){
                 ans++;
             }
        } 
        if(ans==0){
            board[x][y]='B';
            return 1;
        }else{
            board[x][y]=ans+'0';
            return 0;
        }
        }
        return 0;
    }
    void bfs(vector<vector<char>>& board,int x,int y){
        queue<node> q;
        q.push(node(x,y));
        visit[x][y]=true;
        while(!q.empty()){
            node top=q.front();
            q.pop();
            for(int i=0;i<8;++i){
                int xx=top.x+a[i][0];
                int yy=top.y+a[i][1];
                if(update(xx,yy,board)==1){   //update的过程已经包含了judge
                    q.push(node(xx,yy));
                    visit[xx][yy]=true;
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m=board.size();
        n=board[0].size();
        int x=click[0],y=click[1];
        if(board[x][y]=='M')
        {
            board[x][y]='X';
            return board;
        }
        if(update(x,y,board)==1){
            bfs(board,x,y);
        }
        return board;
    }
};
```