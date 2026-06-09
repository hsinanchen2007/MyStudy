```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // k=(y1-y2)/(x1-x2)
        // 小于3个点直接返回点个数
        if (points.size() < 3) {
            return points.size();
        }
        // 斜率和点数的映射
        unordered_map<long double, int> map;
        int max0 = 2;
        for (int i = 0; i < points.size(); i++) {
            // 因为下面的for循环不会把points[i]这个点考虑进去，所以需要额外把这个点加到结果里
            // 这里的add是为了处理点重叠的情况
            int add = 1;
            // 遍历点i之后的所有点
            for (int j = i + 1; j < points.size(); j++) {
                // 如果点j和点i相同，add+1，表示本身点被重叠
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    add++;
                } 
                // 如果斜率无穷，单独处理，因为除以0会溢出
                else if ((points[i][0] - points[j][0]) == 0) {
                    map[INT_MAX]++;
                } 
                // 对应斜率的值+1
                else {
                    map[(long double)(points[i][1] - points[j][1]) / (long double)(points[i][0] - points[j][0])]++;
                }
            }
            // 找出各个斜率里点数最多的
            for (auto item : map) {
                max0 = max(max0, item.second + add);
            }
            // 有可能map为空，这时候add可能为最大值
            max0 = max(max0, add);
            // 清空map，进行下轮循环
            map.clear();
        }
        return max0;
    }
};
```
