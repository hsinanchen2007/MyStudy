也算是多一种做法吧，减少了重复计算，也能过了，但是肯定没有dp正规。
```
using pii = pair<int, int>;
class Solution {
private:
    int n;
    map<pii, int> m;
public:
    int search(vector<vector<int>> &t, int i, int j) {
        auto f = m.find({i, j});
        if (f != m.end()) return f->second;
        if (i == n) return t[i][j];
        int x = search(t, i + 1, j);
        int y = search(t, i + 1, j + 1);
        m[{i, j}] = min(x, y) + t[i][j];
        return min(x, y) + t[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size() - 1;
        return search(triangle, 0, 0);
    }
};
```
