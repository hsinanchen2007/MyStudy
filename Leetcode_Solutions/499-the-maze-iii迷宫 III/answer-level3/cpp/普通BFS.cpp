其实一开始拿到是拒绝的，感觉比较难搞  
写着写着，发现还行，就普通BFS走一把，除了避免回头路，没什么还需要注意的点~  

16ms 13.8M  
--- wangtao HW-2020/2/3  
```
class Solution {
public:
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    string dir[4] = {"u", "d", "l", "r"};
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<pair<int, string>>> visited(m, vector<pair<int, string>>());
        for (int i = 0; i < m; i++) {
            visited[i].resize(n, make_pair(0xFFFF, ""));
        }

        map<int, vector<string>> routeinfo;
        queue<pair<pair<int, int>, pair<int, string>>> qu;
        qu.push(make_pair(make_pair(ball[0], ball[1]), make_pair(0, "")));
        visited[ball[0]][ball[1]] = make_pair(0, "");

        while(!qu.empty()) {
            pair<pair<int, int>, pair<int, string>> topval = qu.front();
            int x = topval.first.first;
            int y = topval.first.second;
            int val = topval.second.first;
            string valstr = topval.second.second;
            qu.pop();

            for (int i = 0; i < 4; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                
                int count = 1;
                int flag = 0;
                while (newx >= 0 && newx < m && newy >= 0 && newy < n && maze[newx][newy] != 1) {
                    if (newx == hole[0] && newy == hole[1]) {
                        flag = 1;
                        break;
                    }
                    newx += d[i][0];
                    newy += d[i][1];
                    count++;
                }
                string valstrtmp = valstr + dir[i];
                int valdist = val + count - 1;
                if (flag == 1) {
                    routeinfo[valdist].push_back(valstrtmp);
                    //cout << valstrtmp << endl;
                } else {
                    newx -= d[i][0];
                    newy -= d[i][1];
                    if (valdist < visited[newx][newy].first || (valdist == visited[newx][newy].first && valstrtmp < visited[newx][newy].second)) {
                        qu.push(make_pair(make_pair(newx, newy), make_pair(valdist, valstrtmp)));
                        visited[newx][newy] = make_pair(valdist, valstrtmp);
                    }
                }
            } 
        }
        // map sorted
        if (routeinfo.size() == 0) {
            return "impossible";
        }
        map<int, vector<string>>::iterator it = routeinfo.begin();
        vector<string> tmp = it->second;
        sort(tmp.begin(), tmp.end());
        return tmp[0];
    }
};
```