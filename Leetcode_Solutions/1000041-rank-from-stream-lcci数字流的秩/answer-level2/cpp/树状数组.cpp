### 解题思路
单点更新，单点查询，最简单的树状数组。

### 代码

```cpp
#define MAXN 50002

class StreamRank {
    vector<int> v;
    int lowbit(int x) {
        return x & (-x);
    }
    
    void update(int idx, int delta) {
        for (; idx < MAXN; idx += lowbit(idx))
            v[idx] += delta;
    }
    
    int query(int idx) {
        int ans = 0;
        for (; idx > 0; idx -= lowbit(idx))
            ans += v[idx];
        return ans;
    }
public:
    StreamRank() {
        v = vector<int>(MAXN);
    }
    
    void track(int x) {
        update(x + 1, 1);
    }
    
    int getRankOfNumber(int x) {
        return query(x + 1);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
```