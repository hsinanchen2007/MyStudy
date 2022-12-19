
先把所有的树放到优先队列里，然后按照高度排序，利用BFS寻找两树之间的最短距离。

```c++ []
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        bx = forest.size();
        by = forest[0].size();
        
        priority_queue<Node> pq;
        
        //把所有树压入优先队列
        for(int i = 0;i < bx; ++i){
            for(int j = 0;j < by; ++j){
                if(forest[i][j] > 1) {
                    pq.push(Node(i,j,forest[i][j],0));
                }
            }
        }
        Node last(0,0,0,0);
        int ans = 0;
        while(pq.size()){
            Node now = pq.top();
            pq.pop();
            //利用BFS求解
            int step = bfs(forest, last, now);
            if (step == -1) return -1;
            last = now;
            ans += step;
            forest[now.x][now.y] = 1;
        }
        return ans;
    }
private:
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int bx, by;
    struct Node{
        int x,y;
        int high,step;
        Node(int _x, int _y, int _h, int _s):x(_x),y(_y),high(_h),step(_s){}
        bool operator<(const Node& rhs) const{
            return high > rhs.high;
        }
    };

    //BFS求两点间距离
    int bfs(vector<vector<int>>& forest, const Node& start, const Node& end){
        queue<Node> que;
        vector<vector<bool>> vis(bx,vector<bool>(by, false));
        que.push(start);
        vis[start.x][start.y] = true;
        while(que.size()){
            Node now = que.front();
            que.pop();
            if(now.x == end.x && now.y == end.y) return now.step;
            for(int i = 0;i < 4; ++i){
                int nx = now.x + dir[i][0];
                int ny = now.y + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || forest[nx][ny] == 0 || vis[nx][ny])
                    continue;
                que.push(Node(nx, ny, 0, now.step+1));
                vis[nx][ny] = true;
            }
        }
        return -1;
    }
};
```
