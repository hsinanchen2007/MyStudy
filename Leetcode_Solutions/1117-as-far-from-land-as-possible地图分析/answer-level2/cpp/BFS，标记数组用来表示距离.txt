### 解题思路
关键思路在于标记数组不再用于标记是否访问过，而是用来表示陆地到海洋的最小值，
只有当扫到它且距离比现在的距离短时才更新并加入队列，最后得到陆地到各个海洋
的最小距离，然后遍历一遍取最大值即可

### 代码

```cpp
class Solution {
public:
    typedef struct{
        int x,y,t;
    }node;
    int maxDistance(vector<vector<int>>& grid) {
        int i,j,k,g,h,m=grid.size(),n=grid[0].size(),v[m][n];
        queue<node>q;
        node p;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j,0});
                    v[i][j]=-1;
                }
                else v[i][j]=INT_MAX;
            }
        }
        while(!q.empty()){
            p=q.front();q.pop();
            g=p.x-1,h=p.y;
            if(g>=0&&g<m&&h>=0&&h<n&&grid[g][h]==0&&v[g][h]>p.t+1){
                q.push({g,h,p.t+1});v[g][h]=p.t+1;
            }//只有v[g][h]>p.t+1时才访问
            g=p.x+1,h=p.y;
            if(g>=0&&g<m&&h>=0&&h<n&&grid[g][h]==0&&v[g][h]>p.t+1){
                q.push({g,h,p.t+1});v[g][h]=p.t+1;
            }
            g=p.x,h=p.y-1;
            if(g>=0&&g<m&&h>=0&&h<n&&grid[g][h]==0&&v[g][h]>p.t+1){
                q.push({g,h,p.t+1});v[g][h]=p.t+1;
            }
            g=p.x,h=p.y+1;
            if(g>=0&&g<m&&h>=0&&h<n&&grid[g][h]==0&&v[g][h]>p.t+1){
                q.push({g,h,p.t+1});v[g][h]=p.t+1;
            }
        }
        k=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                k=max(k,v[i][j]);
            }
        }
        if(k==0||k==INT_MAX)return -1;
        return k;
    }
};
```