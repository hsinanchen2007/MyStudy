### 解题思路

root为NULL返回NULL q 返回q p返回p
right/left递归
return left/right/root

执行用时 :24 ms在所有 C++ 提交中击败了62.93%的用户
内存消耗 :16.2 MB, 在所有 C++ 提交中击败了99.91%的用户

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        if(left != NULL && right != NULL) return root;
        return NULL;
    }
};
```