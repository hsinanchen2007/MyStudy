暴力是n^2的 然后可以对暴力的内层循环用数据结构来优化成log 
内层循环的作用就是找到一个高度比当前点大且下标尽可能远离当前点的值，然后我们用线段树或者树状数组优化一下这个过程，就可以做到nlogn的复杂度。
又加了个离散化防止浪费过多空间。
```
class Solution {
    struct node{
        int l, r, w, lazy;
    }tree[2000001];
public:
    int ret;
    void pushdown(int k) {
        if(tree[k].lazy != 2e9) {
            tree[k<<1].lazy = min(tree[k<<1].lazy, tree[k].lazy);
            tree[k<<1|1].lazy = min(tree[k<<1|1].lazy, tree[k].lazy);
            tree[k<<1].w = min(tree[k<<1].w, tree[k].lazy);
            tree[k<<1|1].w = min(tree[k<<1|1].w, tree[k].lazy);
            tree[k].lazy = 2e9;
        }
    }
    void update(int x, int y, int val, int l, int r, int k = 1) {
        if(x <= l and y >= r) {
            tree[k].w = min(tree[k].w, val);
            tree[k].lazy = min(tree[k].lazy, val);
            return ;
        }
        pushdown(k);
        int mid = l + r >> 1;
        if(x <= mid) update(x, y, val, l, mid, k << 1);
        if(y > mid) update(x, y, val, mid+1, r, k<<1|1);
        tree[k].w = min(tree[k<<1].w, tree[k<<1|1].w);
    }
    void query(int x, int y, int l, int r, int k = 1) {
        if(x <= l and y >= r) {
            ret = min(ret, tree[k].w);
            return ;
        }
        pushdown(k);
        int mid = l + r >> 1;
        if(x <= mid) query(x, y, l, mid, k<<1);
        if(y > mid) query(x, y, mid+1, r, k<<1|1);
    }
    int maxArea(vector<int>& height) {
        if(height.size() == 0) return 0;
        vector<int>g;
        map<int,int>to_id;
        int tot = 0;
        for(auto i : height) g.push_back(i);
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        for(auto i : g) {
            to_id[i] = ++tot;
        }
        int ans = 0;
        for(int i = 0; i <= 200000; i++) tree[i].lazy = 2e9, tree[i].w = 2e9;
        for(int i = 0; i < height.size(); i++) {
            ret = 2e9, query(to_id[height[i]], tot, 1, tot); 
            if(ret != 2e9) ans = max(ans, (i-ret)*height[i]);
            update(1, to_id[height[i]], i, 1, tot);
        }
        for(int i = 0; i <= 200000; i++) tree[i].lazy = 2e9, tree[i].w = 2e9;
        reverse(height.begin(), height.end());
        for(int i = 0; i < height.size(); i++) {
            ret = 2e9, query(to_id[height[i]], tot, 1, tot);//cout << ret << endl;
            if(ret != 2e9) ans = max(ans, (i-ret)*height[i]);
            update(1, to_id[height[i]], i, 1, tot);
        }


        return ans;
    }
};
```
