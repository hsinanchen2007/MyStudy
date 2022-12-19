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
class Solution {
public:
    int dfs(TreeNode* root,int& res)
    {
        if(!root)
            return 0;
        int l=0,r=0;
        if(root->left)
        {
            int tmp = dfs(root->left,res);
            if(root->val == root->left->val)
                l = tmp+1;            
        }
        if(root->right)
        {
            int tmp = dfs(root->right,res);
            if(root->val == root->right->val)
                r = tmp+1;               
        }
        res = res>(r+l)?res:r+l;
        return l>r?l:r;
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root,res);
        return res;
    }
};
```