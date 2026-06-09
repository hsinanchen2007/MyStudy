# 思路：
1，任选三个点，判断是否形成等腰直角三角形
2，若是，则判断第四个点的位置是否合理
```
class Solution {
public:
    using ll = long long;
    ll dist(const vector<int>& p1, const vector<int>& p2) {
        ll dx = p1[0] - p2[0];
        ll dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
    vector<int> opposite(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        vector<int> p4(2, 0);
        p4[0] = p1[0] + p2[0] - p3[0];
        p4[1] = p1[1] + p2[1] - p3[1];
        return p4;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        ll d1 = dist(p2, p3);
        ll d2 = dist(p1, p3);
        ll d3 = dist(p1, p2);
        if (d1 == 0 || d2 == 0 || d3 == 0) return false;
        ll s = d1 + d2 + d3;
        ll max_d = max(d1, max(d2, d3));
        if (2 * max_d != s) return false;
        if (max_d == d1) {
            return d2 == d3 && p4 == opposite(p2, p3, p1);
        } else if (max_d == d2) {
            return d1 == d3 && p4 == opposite(p1, p3, p2);
        } else {
            return d1 == d2 && p4 == opposite(p1, p2, p3);
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ba8096a25014d38bc8185786c2206cb40c4a098be111a0872a6263d87d21d935-image.png)
