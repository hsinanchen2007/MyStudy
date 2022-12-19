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
    void flatten(TreeNode* root) {
       if(!root) return;
       TreeNode* cur = root->right;
       root->right = dfs(root->left);
       TreeNode* a=root;
       while(a->right){
           a=a->right;
       }
       a->right = dfs(cur);
       root->left = NULL;     
    }

    TreeNode* dfs(TreeNode* root){
        if(!root) return NULL;
        TreeNode* res=new TreeNode(root->val);
        TreeNode* cur = root->right;
        res->right = dfs(root->left);
        TreeNode* a=res;
        while(a->right){
            a=a->right;
        }
        a->right = dfs(cur);
        res->left = NULL;
        return res;
    }
};
```