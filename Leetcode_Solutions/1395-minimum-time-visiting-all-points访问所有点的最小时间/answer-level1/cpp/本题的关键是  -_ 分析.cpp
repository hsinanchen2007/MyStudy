### 解题思路


### 代码

```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0;i < points.size() - 1;i++){
            vector<int> pre = points[i],cur = points[i+1];
            int dx = cur[0] - pre[0],dy = cur[1] - pre[1];
            res += max(abs(dx),abs(dy));
        }
        return res;
    }
};
```