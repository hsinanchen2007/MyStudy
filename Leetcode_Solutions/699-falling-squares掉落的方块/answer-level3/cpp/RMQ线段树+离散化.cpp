思路：
要点1：可以使用线段树解。线段树维护区间的最大值。
要点2：离散化，因为数据量还比较大。离散化的巧妙方法是取每个砖块的起始点 `l`, `r` 进行标记。因为如果有其他砖块落到 `[l, r]` 里面，那么就会在`[l, r]` 在插入一个树的节点，所以线段树可以感知到这个中间砖块的变化。
要点3：线段树需要用区间更新的（可以达到60ms），如果用单点更新进行遍历，速度在90~170ms。另外就是区间更新和查找的时候，可以加一些判断条件，提前结束递归，可以加速。

附上两种代码。

线段树区间更新代码
```
class Solution {
public:
    int len = 0;
    vector<int> tree;
    vector<int> lazy;
    void update(int L, int R, int val) {
        doUpdate(L, R, val, 1, len, 1);
    }
    
    void doUpdate(int L, int R, int val, int l, int r, int rt) {
        push_down(rt, l, r);
        int lc = rt << 1;
        int rc = rt << 1 | 1;
        if (L <= l && R >= r) {
            tree[rt] = val;
            if (l != r) {
                lazy[lc] = lazy[rc] = val;
            }
            return;
        }
        if (l > R || r < L || l > r) {
            return;
        }
        int m = (r+l) >> 1;
        if (R <= m) {
            doUpdate(L, R, val, l, m, lc);
        } else if (L > m){
            doUpdate(L, R, val, m+1, r, rc);
        } else {
            doUpdate(L, R, val, l, m, lc);
            doUpdate(L, R, val, m+1, r, rc);
        }
        push_up(rt);
    }
    
    int query(int i, int j) {
        return doQuery(i, j, 1, len, 1);
    }
    
    int doQuery(int L, int R, int l, int r, int rt) {
        push_down(rt, l, r);
        if (L <= l && r <= R) {
            return tree[rt];
        }
        if (l > R || r < L || l > r) {
            return INT_MIN;
        }
        int ret = INT_MIN;
        int m = (r+l) >> 1;
        if (L <= m) {
            ret = max(ret, doQuery(L, R, l, m, rt<<1));
        }
        if (R > m) {
            ret = max(ret, doQuery(L, R, m+1, r, rt<<1 | 1));
        }
        return ret;
    }
    
    void push_up(int rt) {
        tree[rt] = max(tree[rt<<1], tree[rt<<1 | 1]);
    }
    
    void push_down(int rt, int l, int r) {
        if (lazy[rt]) {
            tree[rt] = lazy[rt];
            if (l != r) {
                lazy[rt<<1] = lazy[rt];
                lazy[rt<<1 | 1] = lazy[rt];
            }
            lazy[rt] = 0;
        }
    }
    
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int size = (int)positions.size();
        if (size == 0) {
            return {};
        }
        set<int> s;
        map<int, int> m;
        int index = 1;
        for (auto p : positions) {
            s.insert(p[0]);
            s.insert(p[0] + p[1] - 1);
        }
        
        for (auto p : s) {
            m[p] = index;
            index++;
        }
        
        int Max = (int)s.size();
        len = Max;
        tree = vector<int>(Max << 2, 0);
        lazy = vector<int>(Max << 2, 0);
        vector<int> res;
        int nowMaxHeight = 0;
        for (auto p : positions) {
            int pos = p[0];
            int len = p[1];
            int begin = m[pos];
            int end = m[pos+len-1];
            int tmp = query(begin, end);
            int h = tmp + len;
            update(begin, end, h);
            nowMaxHeight = max(nowMaxHeight, h);
            res.emplace_back(nowMaxHeight);
        }
        return res;
    }
};
```

线段树单点更新
```
class Solution {
public:
    int len = 0;
    vector<int> tree;
    
    void update(int i, int val) {
        doUpdate(i, val, 1, len, 1);
    }
    
    void doUpdate(int i, int val, int l, int r, int rt) {
        if (r== l) {
            tree[rt] = val;
            return;
        }
        int m = (r+l) >> 1;
        if (i <= m) {
            doUpdate(i, val, l, m, rt<<1);
        } else {
            doUpdate(i, val, m+1, r, rt<<1 |1);
        }
        push_up(rt);
    }
    
    int query(int i, int j) {
        return doQuery(i, j, 1, len, 1);
    }
    
    int doQuery(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return tree[rt];
        }
        int ret = INT_MIN;
        int m = (r+l) >> 1;
        if (L <= m) {
            ret = max(ret, doQuery(L, R, l, m, rt<<1));
        }
        if (R > m) {
            ret = max(ret, doQuery(L, R, m+1, r, rt<<1 | 1));
        }
        return ret;
    }
    
    void push_up(int rt) {
        tree[rt] = max(tree[rt<<1], tree[rt<<1 | 1]);
    }
    
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int size = (int)positions.size();
        if (size == 0) {
            return {};
        }
        set<int> s;
        map<int, int> m;
        int index = 1;
        for (auto p : positions) { //离散化，这个思路比较妙，只需要取头尾就行了，因为中间有砖块的话，会插入进去，查询的时候就会查找到
            s.insert(p[0]);
            s.insert(p[0] + p[1] - 1);
        }
        
        for (auto p : s) {
            m[p] = index;
            index++;
        }
        
        int Max = (int)s.size();
        len = Max;
        tree = vector<int>(Max << 2, 0);
        vector<int> res;
        int nowMaxHeight = 0;
        for (auto p : positions) {
            int pos = p[0];
            int len = p[1];
            int begin = m[pos];
            int end = m[pos+len-1];
            int tmp = query(begin, end);
            int m = tmp + len;
            for (int j=begin; j<=end; j++) {
                update(j, m);
            }
            nowMaxHeight = max(nowMaxHeight, m);
            res.emplace_back(nowMaxHeight);
        }
        return res;
    }
};
```