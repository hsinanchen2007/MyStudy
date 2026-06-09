### 解题思路
1、当前节点的最小深度等于 左子树 和 右子树的最小深度 + 1；
2、当前节点为空，且其有兄弟节点时，最小高度应该已兄弟节点的高度计算；


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
    int minDepth(TreeNode* root, bool hasbrother) {
        if (root == NULL) return hasbrother ? INT_MAX : 0;
        return 1 + min(minDepth(root->left, root->right != NULL),
        minDepth(root->right, root->left != NULL));   
    }
    int minDepth(TreeNode* root) {
        return minDepth(root, false);
    }
};
```