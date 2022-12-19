标准树状数组板子，需要注意的是，因为是区间修改，单点查询，所以`update`两次，`query`一次。

```cpp
const int hi = 102;

int lowbit(int x) {
    return x & (-x);
}

class Solution {
    vector<int> live;
    
    void update(int idx, int delta) {
        for (; idx < hi; idx += lowbit(idx))
            live[idx] += delta;
    }
    
    int query(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= lowbit(idx))
            ans += live[idx];
        return ans;
    }
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        live = vector<int>(hi);
        for (int i = 0; i < birth.size(); ++i) {
            update(birth[i] - 1899, 1);
            update(death[i] - 1898, -1);
        }
        int ans = -1, best = 0;
        for (int i = 1; i <= 101; ++i) {
            int year = query(i);
            if (year > best) {
                best = year;
                ans = i + 1899;
            }
        }
        return ans;
    }
};
```