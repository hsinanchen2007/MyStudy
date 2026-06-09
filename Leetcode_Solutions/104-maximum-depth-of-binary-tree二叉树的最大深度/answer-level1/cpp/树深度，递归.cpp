### 解题思路
递归，树的深度 = 树的高度； 树的高度 = max(左子树高度， 右子树高度)+1

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!(root->left) && !(root->right)) return 1;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        return (ld>rd ? ld+1 : rd+1);
    }
};
```