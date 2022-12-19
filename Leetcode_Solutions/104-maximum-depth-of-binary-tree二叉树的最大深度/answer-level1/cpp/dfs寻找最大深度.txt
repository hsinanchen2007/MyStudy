### 解题思路
dfs寻找最大深度

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
    int res=0;
    void dfs(TreeNode* root,int n){
        if(root==NULL){
            res=max(res,n);
            return;
        }
        else{
            dfs(root->left,n+1);
            dfs(root->right,n+1);
        }
    }
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};
```