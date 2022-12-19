# 解法一：
1，记录区间的增量
2，然后从左往后遍历并逐渐合并增量，获取结果
```C++ []
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        // 用来记录增量
        vector<int> marks(length + 1, 0);
        for (auto& v : updates) {
            marks[v[0]] += v[2];
            marks[v[1] + 1] -= v[2];
        }
        vector<int> res(length, 0);
        int s = 0;
        for (int i = 0; i < length; ++i) {
            s += marks[i];
            res[i] = s;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/435b78d0253b9baabadc4c5ad5896f470f47b7102bdeaf7d9d48b85fb7d75705-image.png)


# 解法二：
经典的线段树解法
1，因为查询的时候仅做点查询，不进行区间查询，因此不需要进行向上更新操作，也就没有编写pushUp函数
2，因为增量具有可叠加性，即满足数学上的结合律，因此可以使用懒惰标记，仅在查询的时候做pushDown更新操作
```C++ []
class Solution {
public:
    vector<int> sums;
    vector<int> marks;
    void update(int L, int R, int d, int l, int r, int rt) {
        if (L <= l && R >= r) {
            sums[rt] += d * (r - l + 1);
            marks[rt] += d;
            return;
        }
        int m = l + (r - l) / 2;
        if (m >= L) update(L, R, d, l, m, rt << 1);
        if (m < R) update(L, R, d, m + 1, r, rt << 1 | 1);
    }
    void pushDown(int rt, int ln, int rn) {
        if (marks[rt] != 0) {
            marks[rt << 1] += marks[rt];
            marks[rt << 1 | 1] += marks[rt];
            sums[rt << 1] += ln * marks[rt];
            sums[rt << 1 | 1] += rn * marks[rt];
            marks[rt] = 0;
        }
    }
    int query(int i, int l, int r, int rt) {
        if (l == r) return sums[rt];
        int m = l + (r - l) / 2;
        pushDown(rt, m - l + 1, r - m);
        int res = 0;
        if (m >= i) res = query(i, l, m, rt << 1);
        else res = query(i, m + 1, r, rt << 1 | 1);
        return res;
    }
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        sums = vector<int>(length << 2, 0);
        marks = vector<int>(length << 2, 0);
        for (auto& v : updates) {
            update(v[0], v[1], v[2], 0, length - 1, 1);
        }
        vector<int> res(length, 0);
        for (int i = 0; i < length; ++i) {
            res[i] = query(i, 0, length - 1, 1);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0b49c5953753d915102246aaecdeb86fd5b5ac6971c7eb9af6eedd9f30c71c96-image.png)
