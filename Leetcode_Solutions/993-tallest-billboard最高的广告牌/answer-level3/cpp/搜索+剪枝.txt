- 钢筋按长度升序排序，并计算部分和。
- 从`(0,0)`这一状态开始搜索。其中`first`代表两边的差值，`second`代表较短那边的长度。
- 全局当前最优解记录在`best`变量中
- 搜索空间中，只保留每一个差值对应的最大的$x$（始终保证$x\geq y$）。对于每一个当前状态，如果差值大于剩余钢筋长度总和，或者加上剩余钢筋的总长度也不超过当前最优解的两倍，则放弃该状态。

```cpp
const int dx[3] = {0, 1, 0}, dy[3] = {0, 0, 1};

class Solution {
public:
    int tallestBillboard(vector<int> &rods) {
        int n = rods.size();
        sort(rods.begin(), rods.end());
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + rods[i - 1];
        unordered_map<int, int> x;
        x[0] = 0;
        int best = 0;
        for (int i = n - 1; i >= 0; --i) {
            int rest = sum[i];
            unordered_map<int, int> nx;
            for (auto p : x) {
                int j = p.first;
                for (int k = 0; k < 3; ++k) {
                    int x1 = x[j] + dx[k] * rods[i];
                    int y1 = x[j] + j + dy[k] * rods[i];
                    int delta = abs(x1 - y1);
                    if (delta > rest || (x1 + y1 + rest) / 2 < best)
                        continue;
                    if (delta == 0)
                        best = max(best, x1);
                    if (x1 > y1)
                        swap(x1, y1);
                    nx[delta] = max(nx[delta], x1);
                }
            }
            swap(x, nx);
        }
        return best;
    }
};
```