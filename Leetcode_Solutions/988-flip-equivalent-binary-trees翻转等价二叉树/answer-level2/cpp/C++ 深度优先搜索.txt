```cpp
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2 == NULL;
        if (root2 == NULL) return root1 == NULL;
        if (root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
                flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
    }
};
```

![image.png](https://pic.leetcode-cn.com/98aff4f1da622d9c44cdde8177a6dffcaef1ca96cd3eb7744a7ecd516cf130c0-image.png)
