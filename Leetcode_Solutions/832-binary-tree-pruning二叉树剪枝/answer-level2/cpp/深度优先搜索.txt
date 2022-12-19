### 解题思路
深度优先遍历整个树，当一个节点的val为0，左子树为空，右子树为空时，将此节点置为空。
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
    void deleteTree(TreeNode* &root)
    {
        if(root == NULL)
        return ;
        deleteTree(root -> left);
        deleteTree(root -> right);
        if(root -> val == 0 && root -> left == NULL && root -> right == NULL)
        root = NULL;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
        return NULL;
        deleteTree(root);
        return root;
    }
};
```