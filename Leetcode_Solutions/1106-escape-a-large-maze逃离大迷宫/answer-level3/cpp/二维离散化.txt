
```
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        vector<int> x, y;
        unordered_set<int> set_x, set_y;
        int left = 0, up = 0, right = 1000000 - 1, down = 1000000 - 1;
        blocked.push_back(source);
        blocked.push_back(target);
        for(const vector<int> block: block  ed)
        {
            int i = block[0], j = block[1];
            for(int k = i - 1; k <= i + 1; ++k)
            {
                if(k < up || k > down) continue;
                if(set_x.find(k) == set_x.end())
                {
                    x.push_back(k);
                    set_x.insert(k);
                }
            }
            for(int k = j - 1; k <= j + 1; ++k)
            {
                if(k < left || k > right) continue;
                if(set_y.find(k) == set_y.end())
                {
                    y.push_back(k);
                    set_y.insert(k);
                }
            }
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        int n = x.size(), m = y.size();
        vector<vector<int> > grid(n, vector<int>(m, 0));
        for(const vector<int> block: blocked)
        {
            int i = block[0], j = block[1];
            int new_i = _find(i, x);
            int new_j = _find(j, y);
            grid[new_i][new_j] = 1;
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        vector<vector<bool> > visited(n, vector<bool>(m, false));
        queue<vector<int> > q;
        int s_x = _find(source[0], x), s_y = _find(source[1], y);
        int e_x = _find(target[0], x), e_y = _find(target[1], y);
        q.push(vector<int>({s_x, s_y}));
        visited[0][0] = true;
        while(!q.empty())
        {
            vector<int> cur = q.front();
            q.pop();
            for(int d = 0; d < 4; ++d)
            {
                int xx = cur[0] + dx[d], yy = cur[1] + dy[d];
                if(xx == e_x && yy == e_y)
                    return true;
                if(_check(xx, yy, n, m) && grid[xx][yy] == 0 && !visited[xx][yy])
                {
                    q.push(vector<int>({xx, yy}));
                    visited[xx][yy] = true;
                }
            }
        }
        return false;
    }

private:
    int _find(int v, const vector<int>& x)
    {
        return lower_bound(x.begin(), x.end(), v) - x.begin();
    }

    bool _check(int i, int j, int n, int m)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
};
```
