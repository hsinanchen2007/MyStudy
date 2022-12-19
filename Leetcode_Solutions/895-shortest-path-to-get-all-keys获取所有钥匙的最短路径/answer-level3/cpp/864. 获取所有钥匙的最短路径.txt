

用key的每一位表示每把钥匙的状态，数组`vis[x][y][keys]`表示已到达的位置和钥匙状态。


```c++
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int bx = grid.size(), by = grid[0].size();
        int sx, sy;
        int keys = 0;
        
        //预处理，获取起点位置和钥匙数量
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j] == '@'){
                    sx = i, sy = j;
                }
                else if(isupper(grid[i][j])) keys++;
            }
        }
        
        vector<vector<vector<bool>>> vis(bx, vector<vector<bool>>(by,vector<bool>(1<<keys,false)));
        queue<Node> que;
        
        que.push(Node(sx, sy, 0, 0));
        vis[sx][sy][0] = true;
        
        while(que.size()){
            Node nd = que.front();
            que.pop();
            
            //判断是否已经取得所有钥匙
            if(nd.keys == (1<<keys)-1) return nd.step;
            
            //四个方向遍历
            for(int i=0;i<4;i++){
                int nx = nd.x+dir[i][0];
                int ny = nd.y+dir[i][1];
                int nstep = nd.step;
                int nkeys = nd.keys;
                
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || vis[nx][ny][nkeys] || grid[nx][ny] == '#')
                    continue;
                
                //遇到锁
                if(isupper(grid[nx][ny])){
                    int door = grid[nx][ny] - 'A';
                    //能开锁就开
                    if(nkeys & (1 << door)){
                        nstep = nd.step + 1;
                        que.push(Node(nx, ny, nstep, nkeys));
                        vis[nx][ny][nkeys] = true;
                    }
                    
                //遇到钥匙
                }else if(islower(grid[nx][ny])){
                    int key = grid[nx][ny] - 'a';
                    nkeys |= (1 << key);
                    nstep = nd.step + 1;
                    que.push(Node(nx, ny, nstep, nkeys));
                    vis[nx][ny][nkeys] = true;
                }else{
                    nstep = nd.step + 1;
                    que.push(Node(nx, ny, nstep, nkeys));
                    vis[nx][ny][nkeys] = true;
                }
            }
        }
        return -1;
    }
private:
    struct Node {
        int x,y;
        int step;
        int keys;
        Node(int _x, int _y, int _step, int _keys):x(_x),y(_y),step(_step),keys(_keys){}
    };

    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
};
```
