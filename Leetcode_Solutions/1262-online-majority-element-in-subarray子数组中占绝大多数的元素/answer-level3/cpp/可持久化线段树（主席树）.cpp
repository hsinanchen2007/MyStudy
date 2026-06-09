刚刚学完可持久化线段树（主席树）再来看这个题目发现这个题目正好就可以用主席树来解。主席树就是包含了各个历史版本的权值线段树，维护了各个版本区间内每一个权值的出现个数，这道题正好就是问你在[left, right]这个范围的权值线段树版本内，**出现次数最多的那个数的次数是不是大于threshold**。

学习主席树可以看这个[博客](https://blog.csdn.net/ModestCoder_/article/details/90107874)，需要一些前置技能可以自己看看其他博客。

总的来说，如果[left,right]区间里有一个数出现次数大于一半，那么区间最中间那个数就是那个数，所以只需要把[left,right]区间中间那个数和那个数的出现次数拿出来，看看它的出现次数是不是大于threshold就完事了。

预处理操作用到了离散化和排序，时间复杂度为$O(nlogn)$,每一次询问的时间复杂度为$O(logn)$,所以时间复杂度为$O(nlogn+q*logn)$。

```cpp
const int N = 2e5;

class MajorityChecker {
public:
    int a[N<<5], b[N<<5], t[N<<5], lc[N<<5], rc[N<<5], rt[N<<5];
    int tot, sz, w, n;
    
    void build(int& p, int l, int r)
    {
        p = ++tot;
        if (l == r) { t[p] = 0; return; }
        int mid = l+r>>1;
        build(lc[p], l, mid);
        build(rc[p], mid+1, r);
    }

    int change(int p, int l, int r)
    {
        int np = ++tot;
        lc[np] = lc[p], rc[np] = rc[p], t[np] = t[p]+1;
        if (l == r) return np;
        int mid = l+r>>1;
        if (mid >= w) lc[np] = change(lc[np], l, mid);
        if (mid < w) rc[np] = change(rc[np], mid+1, r);
        return np;
    }

    pair<int, int> ask(int x, int y, int l, int r, int k)
    {
        // return times, value
        if (l == r) return {t[y] - t[x], l};
        int mid = l+r>>1, sum = t[lc[y]] - t[lc[x]];
        
        if (sum >= k) return ask(lc[x], lc[y], l, mid, k);
        if (sum < k) return ask(rc[x], rc[y], mid+1, r, k-sum);
        return {};
    }

    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        for (int i = 1; i <= n; ++ i ) a[i] = arr[i-1], b[i] = a[i];
        sort(b+1, b+n+1);
        sz = unique(b+1, b+n+1) - b - 1;
        build(rt[0], 1, sz);

        //cout << sz;

        for (int i = 1; i <= n; ++ i )
        {
            w = lower_bound(b+1, b+sz+1, a[i])-b;
            rt[i] = change(rt[i-1], 1, sz);
        }
    }
    
    int query(int left, int right, int threshold) {
        pair<int, int> ans = ask(rt[left], rt[right+1], 1, sz, (right-left+2)/2);
        // cout << b[ans.second] << " " << ans.first << " ";
        if (ans.first >= threshold) return b[ans.second];
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```