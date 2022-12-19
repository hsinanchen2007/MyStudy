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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        return diameterOfBinaryTree(root, depth);
    }

    int diameterOfBinaryTree(TreeNode* root, int& depth) {
        if (root == nullptr) {
            depth = 0;
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            depth = 1;
            return 0;
        }

        int left_depth = 0, right_depth = 0;
        int ld = diameterOfBinaryTree(root->left, left_depth);
        int rd = diameterOfBinaryTree(root->right, right_depth);
        depth = 1 + max(left_depth, right_depth);
        return max(left_depth + right_depth, max(ld, rd));
    }
};
```