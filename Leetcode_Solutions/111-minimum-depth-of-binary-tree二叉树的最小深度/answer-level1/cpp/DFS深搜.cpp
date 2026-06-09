### 解题思路
注意边界条件就好

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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root != NULL && root->left == NULL && root->right == NULL)
            return 1;
        DFS(root, 1);
        return minn;
    }
    void DFS(TreeNode* node, int depth)
    {
        if(node != NULL && node->left == NULL && node->right == NULL)
        {
            minn = min(minn, depth);
            return ;
        }
        if(node != NULL && node->left != NULL)
            DFS(node->left, depth + 1);
        if(node != NULL && node->right != NULL)
            DFS(node->right, depth + 1);
    }
private:
    int minn = 0x3f3f3f3f;
};
```