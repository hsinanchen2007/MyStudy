- 对两个点分别查找两遍看是否被困住在障碍物间。找到则表示true即使被困住也是两个都被困住。
- 第一遍没找到且队列如果为空则证明被困住了返回false.没别困住则调换从target找source
- 看target是否被困住。如果两个都没被困住return true;


```
class Solution {
public:
    int Max = 0;   //障碍物能围成的最大面积
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty()) return true;
        unordered_set<long> s, t;
        int n = blocked.size();
        Max = n * (n - 1) / 2;
        for (auto v : blocked) {
            if (abs(source[0] - v[0]) + abs(source[1] - v[1]) <= n)
                s.insert((long)v[0] << 32 | v[1]);
            if (abs(target[0] - v[0]) + abs(target[1] - v[1]) <= n)
                t.insert((long)v[0] << 32 | v[1]);
        }
        return isSurround(s, source, target) && isSurround(t, target, source);
    }
    bool isSurround(unordered_set<long>& visit, vector<int>& sou, vector<int>& tar) {
        queue<pair<int, int>> qu;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        qu.push({sou[0], sou[1]});
        int cnt = 0;
        while (!qu.empty() && cnt <= Max) {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            ++cnt;
            for (int i = 0; i < 4; ++i) {
                int nx = dir[i][0] + x, ny = dir[i][1] + y;
                if (nx < 0 || nx >= 1e6 || ny < 0 || ny >= 1e6) continue;
            //set插入时会返回一个pair<iterator, bool>一个迭代器和是否插入成功布尔值
                if (visit.insert((long)nx << 32 | ny).second) {
                    qu.push({nx, ny});
                    if (tar[0] == nx && tar[1] == ny) return true;
                }
            }
        }
        return !qu.empty();  //为空说明被困住
    }
};
```
