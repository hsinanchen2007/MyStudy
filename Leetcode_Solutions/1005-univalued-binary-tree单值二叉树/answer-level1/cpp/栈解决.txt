一般来说。。递归转非递归可以用栈

这边默认他给的树都是非空树，不然的话第一步val就出错了，需要加情况判断
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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        stack<TreeNode*> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            root = tmp.top();
            tmp.pop();
            if (root->val != val) return 0;
            if (root->left) tmp.push(root->left);
            if (root->right) tmp.push(root->right);
        }
        return 1;
    }
};
```