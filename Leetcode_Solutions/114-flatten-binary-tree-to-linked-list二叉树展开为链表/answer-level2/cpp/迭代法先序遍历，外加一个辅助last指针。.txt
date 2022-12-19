98.31%的91.48%
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        stack<TreeNode*> stac;
        stac.push(root);
        TreeNode *cur = NULL, *last = NULL;
        while (!stac.empty()) {
            cur = stac.top();
            stac.pop();
            if (cur->right)
                stac.push(cur->right);
            if (cur->left)
                stac.push(cur->left);
            if (last) {
                last->left = NULL;
                last->right = cur;
            }
            last = cur;
        }
        last->left = last->right = NULL;
    }
};
```
