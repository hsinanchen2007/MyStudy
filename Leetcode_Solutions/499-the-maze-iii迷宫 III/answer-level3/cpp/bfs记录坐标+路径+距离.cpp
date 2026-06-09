```
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if(ball==hole) return "";
        int m = maze.size(), n = maze[0].size();
        map<vector<int>, int> vis;
        // 数组的三个维度分别是x, y和距离，字符串记录路径
        queue<pair<vector<int>, string>> q;
        q.push({{ball[0], ball[1], 0}, ""});
        // 存储结果
        string res = "";
        int distance = INT_MAX;
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            // 去重，如果当前位置已探索过更近的路径，则不探索
            vector v = {p.first[0], p.first[1]};
            if(vis.find(v) != vis.end() && vis[v] < p.first[2]) continue;
            vis[v] = p.first[2];
            // cout<<p.second<<endl;
            // 上下左右依次尝试
            for(auto& it: direct) {
                int x = p.first[0], y = p.first[1];
                int dx = it.second[0], dy=it.second[1];
                while(x+dx>=0 && x+dx<m && y+dy>=0 && y+dy<n && maze[x+dx][y+dy]==0) {
                    x += dx, y += dy;
                    if(x==hole[0] && y==hole[1]) break;
                }
                // 如果在原地，则不继续处理
                if(x==p.first[0] && y==p.first[1]) continue;
                string ans = p.second + it.first;
                int dis = p.first[2]+abs(x-p.first[0])+abs(y-p.first[1]);
                // 到达终点，根据距离和字典序更新结果
                if(x==hole[0] && y==hole[1]) {
                    // cout<<x<<" "<<y<<" "<<ans<<" "<<res<<dis<<endl;
                    if(dis < distance) res = ans, distance = dis;
                    else if(dis==distance && res > ans) res = ans;
                    continue;
                }
                q.push({{x, y, dis}, ans});
            }
        }
        return res.empty() ? "impossible" : res;
    }
private:
    map<char, vector<int>> direct = 
        {{'u', {-1, 0}}, {'d', {1, 0}}, {'l', {0, -1}}, {'r', {0, 1}}};
};
```
