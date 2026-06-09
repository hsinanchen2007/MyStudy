### 解题思路
- 先将数组按照效率从大到小排序
- 排序后，从前往后，依次按照当前位置为所有选择结果中的最小效率位置
- 计算当前结果，当前结果为：当前位置的效率 \* 从开始到当前位置中至多k个元素的速度最大和（可维护从开始到当前位置大小为k-1的最小堆）

### 代码

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int MOD = 1e9 + 7;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) v.push_back({efficiency[i], speed[i]});
        sort(v.begin(), v.end(), [](const vector<int>& v1, const vector<int>& v2) -> bool{
            return v1[0] > v2[0];
        });

        long long res = 0;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++) {
            if (q.size() > k - 1) {
                int tmp = q.top(); q.pop();
                sum -= tmp;
            }
            q.push(v[i][1]);
            sum += v[i][1];
            res = max(res, sum * v[i][0]);
        }

        return res % MOD;
    }
};
```