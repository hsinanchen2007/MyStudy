### 解题思路

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
class Solution 
{
public:
    int LastVal=0;

    TreeNode* bstToGst(TreeNode* root) 
    {
        traverse(root);
        return root;
    } 
            
    void traverse(TreeNode* root)
    {
        if(root)
        {
            if(root->right) traverse(root->right);

            root->val+=LastVal;
            LastVal=root->val;

            if(root->left) traverse(root->left);
        }
    }
};
```