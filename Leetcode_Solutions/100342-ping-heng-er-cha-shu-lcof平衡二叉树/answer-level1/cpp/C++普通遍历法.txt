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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int l=findwid(root->left);
        int r=findwid(root->right);
        if(l==r||l+1==r||l-1==r) 
        {
            return isBalanced(root->left)&&isBalanced(root->right);
        }
        else return false;
    }
    int findwid(TreeNode* root)
    {
        if(root==nullptr) return 0;
        return max(findwid(root->left),findwid(root->right))+1;
    }
};
```