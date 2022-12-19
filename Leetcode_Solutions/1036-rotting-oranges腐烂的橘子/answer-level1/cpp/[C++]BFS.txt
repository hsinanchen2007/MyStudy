### 解题思路
注意边界情况QAQ

### 代码

```cpp
struct P{
    int x,y,t;
    P(){}
    P(int _x,int _y,int _t):x(_x),y(_y),t(_t){}
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<P> q;
        int sum=0,row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==1) ++sum;
                else if(grid[i][j]==2) q.push(P(i,j,0));
            }
        }
        if(q.empty()) return sum==0?0:-1;
        if(!q.empty()&&sum==0) return 0;
        while(!q.empty()){
            auto p=q.front();q.pop();
            if(p.x>0&&grid[p.x-1][p.y]==1) q.push(P(p.x-1,p.y,p.t+1)),grid[p.x-1][p.y]=2,--sum;
            if(p.y>0&&grid[p.x][p.y-1]==1) q.push(P(p.x,p.y-1,p.t+1)),grid[p.x][p.y-1]=2,--sum;
            if(p.x<row-1&&grid[p.x+1][p.y]==1) q.push(P(p.x+1,p.y,p.t+1)),grid[p.x+1][p.y]=2,--sum;
            if(p.y<col-1&&grid[p.x][p.y+1]==1) q.push(P(p.x,p.y+1,p.t+1)),grid[p.x][p.y+1]=2,--sum;
            if(sum==0) return p.t+1;
        }
        return -1;
    }
};
```