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
    int MAX=0;

    int maxDepth(TreeNode* root) 
    {
        if(!root) return 0;
        DFS(root,1);
        return MAX;
    }

    void DFS(TreeNode* root,int d)
    {
        if(!root->left && !root->right) MAX=max(MAX,d);
        if(root->left) DFS(root->left,d+1);
        if(root->right) DFS(root->right,d+1);
    }
};
```