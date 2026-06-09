### 解题思路
居然碰到了自己面试过程中出过的题
在求树的深度的过程中，保存左右子深度之和的最大值

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
    int length = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return length;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        int lret = depth(root->left);
        int rret = depth(root->right);
        length = max(length, lret+rret);
        return max(lret, rret) + 1;
    }
};
```