### 解题思路
此处撰写解题思路

### 代码

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
    TreeNode* increasingBST(TreeNode* root) {

        auto p = root;
        while (p && p->left)
            p = p->left;

        TreeNode* prev = nullptr;
        function<void(TreeNode*)> inorder = [&](TreeNode* root) {

            if (!root) return;

            inorder(root->left);

            root->left = nullptr;
            if (prev) prev->right = root;
            prev = root;
            
            inorder(root->right);
        };

        inorder(root); // inorder traversal
        return p;
    }
};
```