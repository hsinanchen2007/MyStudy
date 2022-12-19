```
class Solution {
public:
    int abs(int x) {
        return x > 0 ? x : -x;
    }
    int manhattan(const vector<int>& v1, const vector<int>& v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = manhattan(target, {0, 0});
        for (auto& v : ghosts) {
            if (manhattan(target, v) <= dist) return false;
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c40aada8bbcd12a0bcfd79a124287dd0f5493a79e6dfdc3168dccb183ca085d8-image.png)


