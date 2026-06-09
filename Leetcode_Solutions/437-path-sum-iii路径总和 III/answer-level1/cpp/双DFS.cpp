### 解题思路
双dfs

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
    int m, pathnum = 0;
    int pathSum(TreeNode* root, int sum) {
        m = sum;
        if(root == NULL) return 0;
        dfs(root);
        return pathnum;
    }
    void dfs(TreeNode* root){
        rootSum(root, 0);
        if(root->left != NULL) dfs(root->left);
        if(root->right != NULL) dfs(root->right);
        return;
    }
    void rootSum(TreeNode* root, int path){
        path += root->val;
        if(path == m)pathnum++;
        if(root->left != NULL) rootSum(root->left, path);
        if(root->right != NULL) rootSum(root->right, path);
        return;
        
    }
};
```