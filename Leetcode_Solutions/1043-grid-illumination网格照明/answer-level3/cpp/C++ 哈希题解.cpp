```
class Solution {
public:
    int dirs[9][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {1, -1}, {-1, 1}};
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> xlines;
        unordered_map<int, int> ylines;
        unordered_map<int, int> pos_diags;
        unordered_map<int, int> neg_diags;
        for (auto& l : lamps) {
            ++xlines[l[0]];
            ++ylines[l[1]];
            ++pos_diags[l[0] + l[1]];
            ++neg_diags[l[0] - l[1]];
        }
        set<vector<int> > s(lamps.begin(), lamps.end());
        vector<int> res;
        for (auto& q : queries) {
            int x = q[0];
            int y = q[1];
            if (xlines[x] > 0 || ylines[y] > 0 || pos_diags[x + y] > 0 || neg_diags[x - y] > 0) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
            for (int i = 0; i < 9; ++i) {
                int tx = x + dirs[i][0];
                int ty = y + dirs[i][1];
                if (s.count({tx, ty})) {
                    --xlines[tx];
                    --ylines[ty];
                    --pos_diags[tx + ty];
                    --neg_diags[tx - ty];
                    s.erase({tx, ty});
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/fdac11ffbc6fee53c505c790eb8c703b775cc3a3f4ca6d599a6de458e8c9bf04-image.png)
