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
class Solution 
{
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root)
        {
            if(root->left) inorderTraversal(root->left);
            res.push_back(root->val);
            if(root->right) inorderTraversal(root->right);
        }
        return res;
    }
};
```