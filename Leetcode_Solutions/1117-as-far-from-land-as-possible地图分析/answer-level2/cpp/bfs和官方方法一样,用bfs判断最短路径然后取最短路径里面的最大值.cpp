### 解题思路
此处撰写解题思路
```c++
class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> load;
        vector<pair<int,int>> ice;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    load.push_back(pair(i,j));
                }
                else {
                    ice.push_back(pair(i,j));
                }
            }
        }
        if(ice.size()==0 || load.size()==0){
            return -1;
        }
        int maxx = 0;
        for(int i = 0;i<ice.size();i++){
            int minn = 99999999;
            for(int j = 0;j<load.size();j++){
                int sum = abs(ice[i].first-load[j].first)+abs(ice[i].second-load[j].second);
                minn = min(sum,minn);
            }
            maxx = max(maxx,minn);
        }


        return maxx;
    }
};
```
超时代码....
超时代码....
超时代码....
超时代码....
超时代码....




### 代码
BFS 
```cpp
struct node{
    int x,y,step;
};
queue <node > q;
int vis[120][120]={0};
int n,m;
int xx[4]={-1 ,1 ,0 ,0 };
int yy[4]={0 ,0 , -1, 1};
vector<vector<int>> good;
class Solution {
public:
    bool check(int x,int y){
        if(x>=0&&x<n &&y>=0 &&y<m &&vis[x][y]==0){
            return true;
        } 
        return false;
    }
    int find(int x,int y){
        memset(vis,0,sizeof vis);
        while(!q.empty()){
            q.pop();
        }
        node a;
        a.x = x;
        a.y = y;
        a.step = 0;
        q.push(a);
        while(!q.empty()){
            node top = q.front();
            q.pop();
            vis[top.x][top.y]=1;
            for(int i = 0;i<4;i++){
                node temp ;
                temp.x = top.x+xx[i];
                temp.y = top.y+yy[i];
                temp.step = top.step+1;
                if(check(temp.x,temp.y)){
                    if(good[temp.x][temp.y]==1){
                        return temp.step;
                    }
                    else {
                        vis[temp.x][temp.y]=1;
                        q.push(temp);
                    }
                }

            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        good = grid;
        n = grid.size();
        m = grid[0].size();

        int ret = -1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    ret = max(ret,find(i,j));
                }
            }
        }
        return ret;
    }
};
```