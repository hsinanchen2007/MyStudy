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
    stack<int> s;
    bool is=true;

    bool isValidBST(TreeNode* root) 
    {
        if(!root) return true;
        inorder(root);
        return is;
    }

    void inorder(TreeNode* root)
    {
        if(root->left) inorder(root->left);

        if(s.empty() || root->val>s.top()) 
            s.push(root->val);
        else is=false;

        if(root->right) inorder(root->right);
    }
};
```