
一道比较基础的BFS，首先将所有腐烂的橘子入队，并统计新鲜橘子的数量，然后逐层遍历腐烂橘子的相邻节点即可。注意我这里的写法是返回队列中最后一个元素的时间，而不是`cnt==0`时队列中元素的时间。考虑用例`[[1,2,2]]`，第一个2把1腐烂掉后`cnt=0`，这时第二个2还在队列中，如果此时直接返回当前元素的时间就会报错，所以我这里返回队列中最后一个元素的时间。

```c++ []
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bx = grid.size();
        by = grid[0].size();
        
        queue<shared_ptr<Node>> que;
        
        int cnt = 0;
        for(int i = 0;i < bx; ++i){
            for(int j = 0;j < by; ++j){
                if (grid[i][j] == 2){
                    que.push(make_shared<Node>(i, j, 0));
                }else if(grid[i][j] == 1) cnt += 1;
            }
        }
        if(cnt == 0) return 0;
        int total;
        while(que.size()){
            auto now = que.front();
            que.pop();
            total = now->mins;
            for(int i = 0;i < 4;++i){
                int nx = now->x + dir[i][0];
                int ny = now->y + dir[i][1];
                if(nx < 0 || nx >= bx || ny < 0 || ny >= by || grid[nx][ny] != 1)
                    continue;
                grid[nx][ny] = 2;
                cnt -= 1;
                que.push(make_shared<Node>(nx, ny, now->mins+1));
            }
        }
        return cnt <= 0 ? total : -1;
    }
private:
    struct Node{
        int x, y;
        int mins;
        Node(int _x, int _y, int _m):x(_x),y(_y),mins(_m){}
    };
    int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
    int bx, by;
};
```
