```
#define legal(i, j) (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#')

using position = pair<int, int>;
using vertex   = pair<position, position>;
using state    = pair<vertex, int>;

namespace std {
    template <> struct less<state> {
        constexpr bool operator()(const state &lhs, const state &rhs) const {
            return lhs.first < rhs.first;
        }
    };
}

class Solution {
public:
    int minPushBox(vector<vector<char>> &grid) {
        set<state> s; // stores all the state that we have searched
        deque<state> q(1); // a double-ended queue used for managing the bfs
        int n = grid.size(), m = grid[0].size();
        position target;
        // find the source state and target position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S')
                    q[0].first.first = {i, j};
                else if (grid[i][j] == 'B')
                    q[0].first.second = {i, j};
                else if (grid[i][j] == 'T')
                    target = {i, j};
            }
        }
        // start the breadth first search
        while (!q.empty()) {
            s.insert(q.front());
            auto [u, value] = q.front();
            // if the box's position is equal to the target, then we get the result
            if (u.second == target)
                return value;
            q.pop_front();
            // for all possible adjacent state
            for (int k = 0; k < 4; k++) {
                int i = u.first.first  + dir[k][0];
                int j = u.first.second + dir[k][1];
                if (legal(i, j)) {
                    if (i == u.second.first && j == u.second.second) {
                        int _i = i + dir[k][0];
                        int _j = j + dir[k][1];
                        if (legal(_i, _j)) {
                            state new_state = {{{i, j}, {_i, _j}}, value + 1};
                            if (s.find(new_state) == s.end()) {
                                q.push_back(new_state);
                            }
                        }
                    }
                    else {
                        state new_state = {{{i, j}, {u.second.first, u.second.second}}, value};
                        if (s.find(new_state) == s.end()) {
                            q.push_front(new_state);
                        }
                    }
                }
            }
        }
        // if we can't reach the target state, return -1
        return -1;
    }
private:
    static constexpr int dir[4][2] = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0},
    };
};
```

提交了几次，最好才400ms，不知道4ms的大佬怎么写的，太菜了，可能set的查找比较费时
