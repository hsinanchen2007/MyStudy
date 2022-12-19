### 解题思路
执行用时 :172 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :25.4 MB, 在所有 C++ 提交中击败了100.00%的用户

六条（种）路，四个方向。
每个方向可以供三条路走，同时，每条路会有两个出口方向。
当前我们走的这条路有两个方向，把它们取出来，当指示器（i）的方向和这两个方向相等时意味着我们可以向前走，
但是，前方可能没有路（我们即将要到达的路不能和这个方向对接，遍历f[方向][j]即可），
则不能从当前路走到指示器指向的路。
### 代码

```cpp

int f[5][3] = {{0},{1,3,5},{1,4,6},{2,5,6},{2,3,4}};//每个方向可以对接的路的编号
int g[7][2] = {{0},{1,2},{3,4},{2,3},{1,3},{2,4},{1,4}};//每条路的出口方向
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool isflag[305][305];
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(isflag,0,sizeof isflag);
        int row = grid.size(),col = grid[0].size();
        if(row == 1 && col == 1) return true;
        queue<pair<int,int>> que; while(!que.empty()) que.pop();
        que.push(make_pair(0,0));
        isflag[0][0] = true; 
//以第一个例子的初始位置的两个方向为例
        while(!que.empty()){
            pair cur = que.front();que.pop();
            int x = cur.first,y = cur.second;
            int gnum = grid[x][y];//取出当前位置的道路号
            //cout<<"道路号："<<ngum<<endl;
            //例如 gnum = 2;
            int g1 = g[gnum][0],g2 = g[gnum][1];//取出出口方向
            //例如 g1 = 3,g2 =4 ;
            for(int i = 0;i<4;i++){
                int nx = x+dx[i],ny = y+dy[i];
                if(g1 == i+1&&nx>=0&&nx<row&&ny>=0&&ny<col){
                    int ngum = grid[nx][ny];//理论可以到的道路号
                    //例如 理论到达 1,0  道路号ngum =  6 因为 g1 = 3向下
                    for(int j = 0;j<3;j++){
                        if(f[g1][j] == ngum&&isflag[nx][ny] == false)
                        //如果出口可以对接的街道号和当前到达/街道号一样，则可以到达
                        {    
                            //cout<<"可以到达的道路号："<<ngum;
                            isflag[nx][ny] = true;
                            if(row == nx + 1 && col == ny + 1) return true;
                            que.push(make_pair(nx,ny));
                        }
                    }
                }//第一例第一个位置的g2不符合要求，跳过
                if(g2 == i+1&&nx>=0&&nx<row&&ny>=0&&ny<col){
                    int ngum = grid[nx][ny];//理论可以到的街道号
                    for(int j = 0;j<3;j++){
                        if(f[g2][j] == ngum&&isflag[nx][ny] == false)
                        {   
                            //cout<<"可以到达的道路号："<<ngum<<endl;
                            isflag[nx][ny] = true;
                            if(row == nx + 1 && col == ny + 1) return true;
                            que.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
        return false;
    }
};
```