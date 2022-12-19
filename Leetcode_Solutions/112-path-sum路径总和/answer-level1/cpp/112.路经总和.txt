### 解题思路
之前的几个版本简直离谱
是在下输了

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
    bool hasPathSum(TreeNode* root, int sum) {
       
        if(!root) return false;
        if(root&&!root->left&&!root->right)
            return root->val==sum;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }

    
};
```