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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return root;;
        }   
        if(root->left == nullptr && root->right == nullptr )
        {
            return root;
        }
        swap(root->left,root->right);
        if(root->left)
        {
            invertTree(root->left);
        }
        if(root->right)
        {
            invertTree(root->right);
        }
        return root;
    }
};
```