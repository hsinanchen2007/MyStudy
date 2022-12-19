能想到唯一的地方大概就是visited的判断后置了，可以在插入队列前就判断一下？ 速度会差这么多的吗

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目

```
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> Q;
        
        Q.push(make_pair(start[0], start[1]));

        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();
            if (visited[pos.first][pos.second]) continue;
            if (pos.first == destination[0] && pos.second == destination[1]) return true;
            visited[pos.first][pos.second] = 1;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};

            for (int d = 0; d < 4; d++) {
                int i = pos.first;
                int j = pos.second;
                while((i+dx[d] < m) && (i+dx[d] >= 0) && 
                    (j+dy[d] < n) && (j+dy[d] >= 0) && 
                    maze[i+dx[d]][j+dy[d]] == 0 
                ) {
                    i += dx[d];
                    j += dy[d];
                }
                Q.push(make_pair(i, j));
            }

        }

        return false;
    }
};
```
