### 解题思路

### 代码

```cpp
// ax+by=z有解当且仅当z是x, y的最大公约数的倍数。因此我们只需要找到 x, y的最大公约数并判断z是否是它的倍数即可。
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};
/*
class Solution {
public:
    void Help(int a, int b, int x, int y, vector<pair<int, int>>& v) {
        // x 往 y 倒
        pair<int, int> tmp = {min(x, a + b), max(b - (x - a), 0)};
        v.push_back(tmp);
        v.push_back({tmp.first, 0});
        v.push_back({tmp.first, y});
        v.push_back({0, tmp.second});
        v.push_back({0, y});
        v.push_back({x, 0});
        v.push_back({x, tmp.second});
    };
    bool canMeasureWater(int x, int y, int z) {
        unordered_map<int, unordered_map<int, int>> m;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({x, y});
        m[0][0] = 1;
        m[x][y] = 1;
        while (q.empty() == false) {
            pair<int, int> curr = q.front();
            q.pop();
            if (curr.first == z || curr.second == z || curr.first + curr.second == z) {
                return true;
            }
            vector<pair<int, int>> nxt;
            Help(curr.first, curr.second, x, y, nxt);
            Help(curr.second, curr.first, y, x, nxt);
            for (auto p : nxt) {
                if (m[p.first][p.second] == 1) {
                    continue;
                }
                q.push(p);
                m[p.first][p.second] = 1;
            }
        }
        return false;
    }
};*/
```