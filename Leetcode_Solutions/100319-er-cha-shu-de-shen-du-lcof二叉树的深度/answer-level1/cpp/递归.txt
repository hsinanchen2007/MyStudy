### 解题思路
return max(dfs(root->left,n+1),dfs(root->right,n+1));

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
    int dfs(TreeNode* root,int n){
        if(root==NULL)
            return n;
        return max(dfs(root->left,n+1),dfs(root->right,n+1));
    }
    int maxDepth(TreeNode* root) {
        return dfs(root,0);
    }
};
```