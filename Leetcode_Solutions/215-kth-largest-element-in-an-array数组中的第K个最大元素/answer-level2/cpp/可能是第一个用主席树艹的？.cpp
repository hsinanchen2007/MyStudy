```
class Solution {
public:
    static const int maxn = 1e5 + 100;
    int rt[maxn];
    struct node {
        int l, r;
        int sum;
    } T[maxn * 20];
    int tot = 0; 
    vector<int> v;
    int getid(int k) { return lower_bound(v.begin(), v.end(), k) - v.begin() + 1; }
    void build(int &o, int l, int r) {
        o = ++tot;
        T[o].sum = 0;
        if (l == r) return;
        int mid = (l + r) / 2;
        build(T[o].l, l, mid);
        build(T[o].r, mid + 1, r);
    }
    void update(int l, int r, int &now, int last, int k) {
        T[++tot] = T[last];
        now = tot;
        T[tot].sum++;
        if (l == r) return;
        int mid = (l + r) / 2;
        if (k <= mid)
            update(l, mid, T[now].l, T[last].l, k);
        else
            update(mid + 1, r, T[now].r, T[last].r, k);
    }
    int query(int l, int r, int x, int y, int k) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int cnt = T[T[y].l].sum - T[T[x].l].sum;
        if (cnt >= k)
            return query(l, mid, T[x].l, T[y].l, k);
        else
            return query(mid + 1, r, T[x].r, T[y].r, k - cnt);
    }
    int findKthLargest(vector<int>& nums, int k) {
        for(auto x:nums) v.push_back(x);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        build(rt[0],1,nums.size());
        for(int i=1;i<=nums.size();i++)
            update(1,nums.size(),rt[i],rt[i-1],getid(nums[i-1]));
        return v[query(1,nums.size(),rt[0],rt[nums.size()],nums.size()-k+1)-1];
    }
};
```
存粹闲的蛋疼QAQ