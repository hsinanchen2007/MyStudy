### 解题思路

辣鸡线段树，枚举左端点，利用线段树（数据存数组前缀和）找到符合大小要求最靠左的索引

随便写了一下，代码可能有点丑，感觉线段树查询还可以再优化一下？

![image.png](https://pic.leetcode-cn.com/0e66809c2b7e4f510d3311836ea11dbfd99bdd993295ed0c5017108508871c45-image.png)


### 代码

```cpp
class Solution {
public:
    std::vector<int> tree;

    void Build(int o, int l, int r, const std::vector<int>& arr) {
        if (l == r) {
            tree[o] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        Build(o * 2, l, m, arr);
        Build(o * 2 + 1, m + 1, r, arr);
        tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
    }

    int Query(int o, int l, int r, int ql, int qr, int val) {
        if (tree[o] < val) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int ret = -1, m = (l + r) / 2;
        if (ql <= m) {
            ret = Query(o * 2, l, m, ql, qr, val);
        }
        if (ret == -1 && qr > m) {
            ret = Query(o * 2 + 1, m + 1, r, ql, qr, val);
        }
        return ret;
    }

    int shortestSubarray(std::vector<int>& A, int K) {
        tree.resize(A.size() * 4 + 5);
        std::vector<int> pref(A.size() + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            pref[i + 1] = pref[i] + A[i];
        }
        Build(1, 1, A.size(), pref);
        int ret = -1;
        for (int l = 0; l < A.size(); ++l) {
            int r = Query(1, 1, A.size(), l + 1, A.size(), K + pref[l]);
            if (r != -1) {
                ret = ret == -1 ? r - l : std::min(ret, r - l);
            }
        }
        return ret;
    }
};
```