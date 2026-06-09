### 解题思路
joshua分享：以斜率为键，斜率出现的次数为值，统计每一轮斜率出现情况，得出最多的值

### 代码

```cpp
class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        // 以斜率为键，斜率出现的次数为值，统计每一轮斜率出现情况，得出最多的值
        map<double, int> m;
        // 初始化返回 0，1
        vector<int> ans({0, 1});
        int tMax = -1;
        double k = 0;

        // 第一个基准点从左到右，第二个基准点从右到左开始扫描
        for(int i = 0; i < points.size(); i++) {
            for(int j = points.size()-1; j >= 0; j--) {
                // 不计算自己
                if(i == j) continue;

                // 计算斜率，分为三种情况 DIFFX = 0, DIFFY = 0, 一般的情况
                if(points[i][0] == points[j][0])
                    k = 0x7fffffffffffffff;
                else if(points[i][1] == points[j][1])
                    k = 0;
                else {
                    k = (points[j][1]-points[i][1]) / ( (points[j][0]-points[i][0]) * 1.0 );
                }

                // 当前的斜率次数+1
                m[ k ]++;

                // 更新当前的位置
                if(m[k] > tMax) {
                    tMax = m[k];
                    ans[0] = i;
                    ans[1] = j;
                }else if(m[k] == tMax) {
                    // 如果当前轮的次数相等，需要更新 Y 到更小的值
                    if(ans[0] == i) ans[1] = min(ans[1], j);
                }
            }
            m.erase(m.begin(), m.end());
        }
        return ans;
    }
};
```