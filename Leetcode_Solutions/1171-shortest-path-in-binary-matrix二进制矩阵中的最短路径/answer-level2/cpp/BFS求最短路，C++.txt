利用BFS的方法来求最短路径，也可以用狄杰斯特拉算法，也是求单源最短路，一般求最短路可以用BFS或者DFS
代码的思路不难，用DFS的话会超时
```
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<int> q;
        vector<int> rowdir={-1,1,0,0,-1,1,-1,1};//上下左右 左上左下，右上右下8个方向
        vector<int> coldir={0,0,-1,1,-1,-1,1,1};
        vector<int> minlen(grid.size()*grid.size(),1e6);
        vector<int> vis(grid.size()*grid.size());
        if(!grid[0][0])
        q.push(0);
        minlen[0]=1;
        while(!q.empty())
        {
            int now=q.front();q.pop();
            int row=now/grid.size();
            int col=now%grid.size();
            for(int i=0;i<rowdir.size();i++)
            {
                int num = (row+rowdir[i])*grid.size()+col+coldir[i];
                int x=row+rowdir[i],y=col+coldir[i];
                if(x>=0&&x<grid.size()&&y>=0&&y<grid.size()&&!vis[num]&&grid[x][y]==0)
                {
                    q.push(num);
                    //cout<<num<<endl;
                    vis[num]=1;
                    minlen[num]=min(minlen[num],minlen[now]+1);
                }
            
            }
        }
        return minlen[grid.size()*grid.size()-1]==1e6?-1:minlen[grid.size()*grid.size()-1];
    }
};
```
