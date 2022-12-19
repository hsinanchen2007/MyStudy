```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i=0; i<points.size(); i++) {
            int dup = 1;
            map<pair<int,int>, int> m;
            for(int j=i+1; j<points.size(); j++) {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    dup++;
                    continue;
                }
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int gd = gcd(dx, dy);
                m[{dx / gd, dy / gd}]++;
            }
            res = max(res, dup);   // 没有斜率的情况
            for(const auto& a:m) {
                res = max(res, a.second+dup);
            }
        }
        return res;
    }
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
};
```
