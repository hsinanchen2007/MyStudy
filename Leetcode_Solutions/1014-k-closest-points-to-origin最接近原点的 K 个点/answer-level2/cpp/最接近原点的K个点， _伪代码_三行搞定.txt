标题夸张了点，实际上加上容错，以及代码展开，不止这么点哈，能有个8,9行吧。 ：）
另外直接修改了原数组，实际内存开销也算是优化了一点。 时间击败 80%，空间击败70%

解题思路（三行伪代码说明）：

    1， 计算x*x+y*y，放入原数组下标2位置, 既然是比大小排序，就不用再开平方了。
    2， 依据下标2，也就是x*x+y*y的值进行排序。
    3， 取前K个数据输出。

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        if (K >= points.size()) { return points; }
        for (auto &p: points) { p.push_back(p[0]*p[0]+p[1]*p[1]); }
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){ return a[2] < b[2]; });
        for (int i = 0; i < K; i++) { ret.push_back({points[i][0], points[i][1]}); }
        return ret;
    }
};
```

更新：

换种写法，内存节省10%，时间性能差不多。
```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        #define DD(p) (p[0]*p[0] + p[1]*p[1])
        int size = points.size();
        if (K >= size) { return points; }
        vector<int> index(size);
        for(int i = 0; i < size; i++) { index[i] = i; }
        sort(index.begin(), index.end(), [&](int &a, int &b){ return DD(points[a]) < DD(points[b]); });
        vector<vector<int>> ret;
        for (int i = 0; i < K; i++) { ret.push_back(points[index[i]]); }
        return ret;
    }
};
```
