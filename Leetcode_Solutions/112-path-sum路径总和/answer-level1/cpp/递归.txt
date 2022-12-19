### 解题思路
要注意输入节点值可能为负，所以不要用sum<0来优化。

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
    bool hasPathSum_core(TreeNode* root, int sum) {
        if (NULL==root) return false;
        sum -= root->val;
        if (root->left == NULL && root->right==NULL) {
            if (sum == 0) return true;
            else return false;
        }
        return hasPathSum_core(root->left, sum) || hasPathSum_core(root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return hasPathSum_core(root, sum);
    }
};
```