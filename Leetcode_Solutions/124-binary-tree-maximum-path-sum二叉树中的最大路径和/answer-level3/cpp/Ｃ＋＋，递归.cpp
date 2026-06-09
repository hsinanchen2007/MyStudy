### 解题思路
之前求直径什么的中等题好像和这个困难没差；
关键是max(0,dfs(root->left))； 需要和0比较，因为可以不选！！

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
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left = max(0,dfs(root->left));
        int right = max(0,dfs(root->right));
        if(left+right+root->val>res) res=left+right+root->val;
        return root->val+max(left,right);
    }
};
```