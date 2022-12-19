队列就是广搜，其实我觉得广搜在这道题比深搜好些，因为深搜的话也是一样要全走一遍的，没办法保证最长的深度不在最右边
就是消耗空间有点大。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> t;
        t.push({root, 1});
        int d;
        TreeNode *p;
        while (!t.empty()) {
            p = t.front().first;
            d = t.front().second;
            t.pop();
            if (p->left) t.push({p->left, d + 1});
            if (p->right) t.push({p->right, d + 1});
        }
        return d;
    }
};
```