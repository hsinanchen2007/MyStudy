### 解题思路

对每个节点,判断其左右两边的最大深度差,递归调用左右子节点

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
    int getMaxiumDepth(TreeNode *root)
    {
        return root == NULL ? 0 : max(getMaxiumDepth(root->left), getMaxiumDepth(root->right)) + 1;
    }
    // int getMiniumDepth(TreeNode *root)
    // {
    //     return root == NULL ? 0 : min(getMiniumDepth(root->left), getMiniumDepth(root->right)) + 1;
    // }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return abs(getMaxiumDepth(root->left)-getMaxiumDepth(root->right))<=1 &&
                isBalanced(root->left) && isBalanced(root->right);
    }
};
```