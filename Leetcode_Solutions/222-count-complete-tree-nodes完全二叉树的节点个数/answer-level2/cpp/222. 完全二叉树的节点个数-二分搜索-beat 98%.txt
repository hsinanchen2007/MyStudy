找出最下层的范围，然后使用基于 upperbound 的二分搜索。

```
int countNodes(TreeNode* root) {
    int h = 0, lo = 0, hi = 0;
    if (!root) return 0;

    TreeNode* node = root;
    while (node) {
        ++h;
        node = node->left;
    }
    
    lo = 1 << (h - 1); // 4
    hi = (1 << h) - 1; // 7

    while (lo < hi) {
        int mid = lo + (hi - lo + 1 >> 1); // 6,7
        int n = mid; // 6,7
        stack<int> path; // 6,3 | 7,3
        while (n != 1) {
            path.push(n);
            n >>= 1;
        }
        node = root;
        int cur = 1;
        while (node && !path.empty()) {
            if ((cur << 1) == path.top()) { // 1*2 == 3, 3*2 == 6 | 1*2 == 3, 3*2 == 7
                node = node->left;
            } else {
                node = node->right;
            }
            cur = path.top();
            path.pop();
        }

        if (node) {
            lo = mid; // 6
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}
```
