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
    bool flag;
public:
    void dfs(TreeNode* root, int sum, int pathSum){
        pathSum += root->val;
        if(!root->left && !root->right){   //递归边界
            if(pathSum == sum) flag = true;
            pathSum -= root->val;
            return;
        }else {
            if(root->left){
                dfs(root->left, sum, pathSum);
            }
            if(root->right){
                dfs(root->right, sum, pathSum);
            }
            pathSum -= root->val;   //回溯
        }
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return {};
        flag = false;
        dfs(root, sum, 0);
        return flag;
    }
};
```