线段树，自己写好多坑啊。。。
```
class NumArray {
public:
    vector<int> num;
    vector<int> tree;
    int cur = 0;
    NumArray(vector<int>& nums) {
        num = nums;
        if (nums.size() == 0) {
            return;
        }
        tree = vector<int>(nums.size() << 2, 0); //不能简单用 nums.size() << 1，因为num.size()不是满的子节点数目
        
        build(1, (int)nums.size(), 1, nums); //从1开始是因为 0 << 1 = 0
    }

    void update(int i, int val) {
        doUpdate(i+1, val, 1, (int)num.size(), 1); //因为从1开始，所以引索都需要加1
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

    int sumRange(int i, int j) {
        return doSumRange(i+1, j+1, 1, (int)num.size(), 1);
    }

    int doSumRange(int L, int R, int l, int r, int rt) {
        if (L <= l && r <= R) {
            return tree[rt];
        }
        int ret = 0;
        int m = (r+l) >> 1;
        if (L <= m) {
            ret += doSumRange(L, R, l, m, rt<<1);
        }
        if (R > m) {
            ret += doSumRange(L, R, m+1, r, rt<<1 | 1);
        }
        return ret;
    }

    void build(int l, int r, int rt, vector<int>& nums) {
        if (r == l) {
            tree[rt] = nums[cur++];
            return;
        }
        int m = (r+l) >> 1;
        build(l, m, rt << 1, nums);
        build(m+1, r, rt << 1 | 1, nums);
        push_up(rt);
    }

    void push_up(int rt) {
        tree[rt] = tree[rt<<1] + tree[rt<<1 | 1];
    }
};
```