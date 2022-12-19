

```
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int dic[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        unordered_map<int,unordered_set<int>> m;
        /*dic[0]:向上；dic[1]:向下····以此类推*/
        //用map记录街道连接的方向
        m[1]={2,3};//左和右
        m[2]={0,1};//上和下
        m[3]={1,2};//下和左
        m[4]={1,3};//下和右
        m[5]={0,2};//上和左
        m[6]={0,3};//上和右
        unordered_set<int> vis;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int p=q.front();q.pop();
            vis.insert(p);
            int x=p/c,y=p%c;
            if(x==r-1&&y==c-1)
                 return true;
            for(int i:m[grid[x][y]]){
                int tx=x+dic[i][0];
                int ty=y+dic[i][1];
                int tp=tx*c+ty;
                if(tx<0||tx>=r||ty<0||ty>=c||vis.count(tp)) continue;
                int ti=i%2==0?i+1:i-1;//与当前走的方向相反的方向，用于检测邻居与自己是否相通
                if(m[grid[tx][ty]].count(ti))          
                     q.push(tp);             
            }            
        }
        return false;
    }
};

```