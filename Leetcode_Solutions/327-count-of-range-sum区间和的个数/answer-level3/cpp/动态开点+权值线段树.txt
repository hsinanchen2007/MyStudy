这种解法用到了动态开点+权值线段树去维护前缀和出现的次数。因为数据太大了，还需要用到离散化，不然空间会爆掉。这不是一篇题解，只是给出代码提供一种思路，对于代码有问题可以留言。

```cpp
const int N = 1e5+10;

class Solution {
public:
    typedef long long ll;
    int lc[N], rc[N], t[N];
    ll sum[N], b[N];
    int cnt = 0, root = 0;

    void change(int& p, int l, int r, int wh, int val)
    {
        if (!p) p = ++cnt;
        if (l == r) { t[p] += val; return; }
        int mid = l+r>>1;
        if (mid >= wh) change(lc[p], l, mid, wh, val);
        if (mid < wh) change(rc[p], mid+1, r, wh, val);
        t[p] = t[lc[p]] + t[rc[p]];
    } 

    // in [l,r], ask [L,R]
    int ask(int p, int l, int r, int L, int R)
    {
        if (!p) return 0;
        if (l >= L && r <= R) return t[p];
        int mid = l+r>>1, ans = 0;
        if (mid >= L) ans += ask(lc[p], l, mid, L, R);
        if (mid < R) ans += ask(rc[p], mid+1, r, L, R);
        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size(), ans = 0;
        
        for (int i = 1; i <= n; ++ i ) 
        {
            sum[i] = sum[i-1] + nums[i-1];
            b[i] = sum[i];
        }

        sort(b, b+n+1);
        int sz = unique(b, b+n+1) - b - 1;

        change(root, 0, sz, lower_bound(b, b+sz+1, 0)-b, 1);

        for (int i = 1; i <= n; ++ i )
        {
            ll L = sum[i]-1ll*upper, R = sum[i]-1ll*lower;
            L = lower_bound(b, b+sz+1, L)-b;
            R = upper_bound(b, b+sz+1, R)-b-1;
            ans += ask(root, 0, sz, L, R);
            
            int add = lower_bound(b, b+sz+1, sum[i])-b;
            change(root, 0, sz, add, 1);
        }

        return ans;
    }
};
```
