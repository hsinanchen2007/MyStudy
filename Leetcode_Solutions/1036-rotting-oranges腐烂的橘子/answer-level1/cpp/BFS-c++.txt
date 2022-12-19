### 解题思路
标准的BFS题，不用讲啥，用了很慢的办法，只求把框架记牢

### 代码

```cpp
class Solution {
public:
    //增量数组
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    struct Node{
        int x;
        int y;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int num_inq = 0;  //记录入过队的橘子数
        int num = 0;  //记录橘子数量
        queue<Node> q;
        vector<vector<int>> inq(grid.size(), vector<int>(grid[0].size(), false));
        //先找为所有为2的入队（第一层）
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) num++;
                else if(grid[i][j] == 2) {
                    num++;
                    Node node;
                    node.x = i, node.y = j;
                    inq[i][j] = true;
                    q.push(node);
                    num_inq++;
                } 
            }
        }
        while(!q.empty()){
            if(num_inq == num) break;  //必须特判，因为最后一次虽然所有的都烂了，但队列中仍有要继续遍历，只不过啥都访问不到了
            ans++;  //遍历一层
            //一次一层
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node top = q.front();
                q.pop();
                //访问上下左右
                for(int j = 0; j < 4; j++) {
                    int x = top.x + X[j];
                    int y = top.y + Y[j];
                    if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;  //判断是否越界
                    if(inq[x][y] == false && grid[x][y] == 1) { //没访问过，没腐烂
                        grid[x][y] = 2;
                        inq[x][y] = true;
                        Node node;
                        node.x = x, node.y = y;
                        q.push(node);
                        num_inq++;
                    }
                }
            }
        }
        if(num_inq == num) return ans;  //所有橘子都烂了
        return -1; //并未全烂
    }
};
```