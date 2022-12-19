### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        if (k == 1) {
            long ret = 0;
            for (int i = 0; i < n; i++)
                ret = max(ret, (long)speed[i] * efficiency[i]);
            return ret % 1000000007;
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back(make_pair(efficiency[i], speed[i]));
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){return a.first > b.first;});
        priority_queue<int, vector<int>, greater<int>> maxn;
        long maxsumn = 0;
        long ret = 0;
        for (int i = 0; i < k - 1; i++) {
            maxn.push(v[i].second);
            maxsumn += v[i].second;
            ret = max(ret, maxsumn * v[i].first);
        }
        for (int i = k - 1; i < n; i++) {
            ret = max(ret, (maxsumn + v[i].second) * v[i].first);
            if (v[i].second > maxn.top()) {
                maxsumn -= maxn.top();
                maxsumn += v[i].second;
                maxn.pop();
                maxn.push(v[i].second);
            } 
        }
        return ret % 1000000007;
    }
};
```