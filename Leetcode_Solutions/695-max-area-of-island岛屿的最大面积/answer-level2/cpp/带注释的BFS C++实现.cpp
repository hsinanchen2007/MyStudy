遍历+BFS
易理解的实现，虽然很丑陋
```
class Solution {
/*
思路：遍历图，发现为1的点就以此为起点进行BFS求面积并把走过的地方标为已访问
最后返回面积最大的子图
*/
public:
    struct Point{//存点的结构体
        int x;
        int y;
        Point(int i,int j){
            x=i;
            y=j;
        }
    };
    int visit[51][51];//标记数组，=1表示该点访问过
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(visit,0,sizeof(visit));
        int ans=0;
        int size=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){//遍历图
                if(grid[i][j]==1&&visit[i][j]==0){
                    size=getSize(grid,i,j);//碰到为1且没有被访问的点BFS求面积
                    ans=ans>size?ans:size;
                }
            }
        }
        return ans;
    }
    int getSize(vector<vector<int>>& grid,int i,int j){//BFS算法
        queue<Point*> q;
        Point *start=new Point(i,j);
        q.push(start);
        int size=1;
        visit[i][j]=1;
        while(!q.empty()){
            int x=q.front()->x;
            int y=q.front()->y;
            q.pop();
            //根据队首的点生成下一个可以访问的点
            if(x-1>=0&&grid[x-1][y]==1&&visit[x-1][y]==0){
                q.push(new Point(x-1,y));
                visit[x-1][y]=1;
                size++;
            }
            if(x+1<grid.size()&&grid[x+1][y]==1&&visit[x+1][y]==0){
                q.push(new Point(x+1,y));
                visit[x+1][y]=1;
                size++;
            }
            if(y-1>=0&&grid[x][y-1]==1&&visit[x][y-1]==0){
                q.push(new Point(x,y-1));
                visit[x][y-1]=1;
                size++;
            }
            if(y+1<grid[x].size()&&grid[x][y+1]==1&&visit[x][y+1]==0){
                q.push(new Point(x,y+1));
                visit[x][y+1]=1;
                size++;
            }
        }
        return size;
    }
};
```
