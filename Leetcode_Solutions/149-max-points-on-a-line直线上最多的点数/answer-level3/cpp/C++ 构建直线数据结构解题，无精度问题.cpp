构建直线的数据结构，数据结构记录如下信息即可：
1，直线某个点
2，直线最初构建时的两点在x轴,y轴上的差值
3，该直线经过的点的下标集合
由于不涉及到浮点数，因此无精度损失问题
然后就可以直观的进行计算了，代码如下：
```
class Solution {
public:
    struct Line {
        int x, y, dx, dy;
        int count;
        vector<int> node_indices;
        Line(int _x, int _y, int _dx, int _dy, int _count) 
            : x(_x), y(_y), dx(_dx), dy(_dy), count(_count) {}
    };
    // 以下方式计算可以兼容直线垂直、水平的情况，用long防止int溢出
    bool onLine(const Line& line, vector<int>& p) {
        return (long)(p[1] - line.y) * (long)line.dx == (long)(p[0] - line.x) * (long)line.dy;
    }
    Line create(const vector<int>& p1, const vector<int>& p2,
            map<vector<int>, int>& point_counts) {
        return Line(p1[0], p1[1], p2[0] - p1[0], p2[1] - p1[1], 
                point_counts[p1] + point_counts[p2]);
    }
    int maxPoints(vector<vector<int>>& ori_points) {
        map<vector<int>, int> point_counts;
        for (auto& point : ori_points) ++point_counts[point];
        vector<vector<int> > points;
        for (auto& p : point_counts) points.push_back(p.first);
        int N = points.size();
        if (N <= 2) {
            int count = 0;
            for(auto& p : point_counts) count += p.second;
            return count;
        }
        vector<Line> lines;
        lines.push_back(create(points[0], points[1], point_counts));
        lines[0].node_indices.push_back(0);
        lines[0].node_indices.push_back(1);
        for (int i = 2; i < N; ++i) {
            vector<bool> seen(i, false);
            auto p = points[i];
            int s = lines.size();
            for (int j = 0; j < s; ++j) {
                if (onLine(lines[j], p)) {
                    lines[j].count += point_counts[p];
                    lines[j].node_indices.push_back(i);
                } else {
                    for (auto k : lines[j].node_indices) {
                        if (!seen[k]) {
                            lines.push_back(create(p, points[k], point_counts));
                            lines.back().node_indices.push_back(i);
                            lines.back().node_indices.push_back(k);
                            seen[k] = true;
                        }
                    }
                }
            }
        }
        int res = 2;
        for (auto& line : lines) {
            res = max(res, line.count);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0a7f5d0fdc3c6b5c06ed4cedba444f43d4992b0248df9c4a4bf8ae1e68ff80b1-image.png)
