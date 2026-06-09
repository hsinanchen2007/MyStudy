```C++ []
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL) return root;
        auto l = root->left;
        auto r = root->right;
        root->left = NULL;
        root->right = NULL;
        auto res = upsideDownBinaryTree(l);
        l->left = r;
        l->right = root;
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5a99b13ac904f97c17f8579bf778df6ddf52a82f9cf372e642c49fe70ddaa698-image.png)
