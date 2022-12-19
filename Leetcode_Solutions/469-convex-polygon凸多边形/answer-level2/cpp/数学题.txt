### 解题思路
判断斜率变化方向，比如是否从递增化为递减

### 代码

```cpp
class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long pre = 0;
        
        points.push_back(points[0]);
        points.push_back(points[1]);
        
        for (int i = 0; i < n; i++) {
            int dx1 = points[i + 1][0] - points[i][0];
            int dy1 = points[i + 1][1] - points[i][1];
            int dx2 = points[i + 2][0] - points[i][0];
            int dy2 = points[i + 2][1] - points[i][1];
            long cur = dx1 * dy2 - dx2 * dy1;
            
            if (cur != 0) {
                if (cur * pre < 0) {
                    return false;
                }
                pre = cur;
            }
        }
        
        return true;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
```