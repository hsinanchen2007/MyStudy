### 解题思路

28ms cpp bfs

### 代码

```cpp
class Solution {
public:
    bool sig[101][101];
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& des) {
        memset(sig[0],0,sizeof(sig));
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        sig[start[0]][start[1]]=1;
        int m=maze.size(),n=maze[0].size();
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x1=x+dx[i],y1=y+dy[i];
                if(x1<0||y1<0||x1==m||y1==n||maze[x1][y1])continue;
                while(x1>=0&&y1>=0&&x1<m&&y1<n&&maze[x1][y1]==0/*&&(x1!=des[0]||y1!=des[1])*/)x1+=dx[i],y1+=dy[i];
                //if(x1==des[0]&&y1==des[1])return true;
                x1-=dx[i];y1-=dy[i];
                if(sig[x1][y1])continue;
                if(x1==des[0]&&y1==des[1])return true;
                sig[x1][y1]=1;
                q.push({x1,y1});
            }
        }
        return false;
    }
};
```