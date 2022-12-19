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
    bool find=false;

    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(!root) return find;
        DFS(root,0,sum);
        return find;
    }

    void DFS(TreeNode* root,int _sum,int sum)
    {
        _sum+=root->val;
        if(_sum==sum && !root->left &&!root->right) find=true;
        if(root->left) DFS(root->left,_sum,sum);
        if(root->right) DFS(root->right,_sum,sum);
    }
};
```