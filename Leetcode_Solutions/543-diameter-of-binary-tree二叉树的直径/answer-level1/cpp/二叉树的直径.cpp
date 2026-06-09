### 解题思路
注意优化~

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
        if (!root) {
            return 0;
        }
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
    }
    int maxDepth(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int ld = maxDepth(root->left, diameter);
        int rd = maxDepth(root->right, diameter);
        diameter = max(diameter, ld + rd);
        return 1 + max(ld, rd);
    }
};
```