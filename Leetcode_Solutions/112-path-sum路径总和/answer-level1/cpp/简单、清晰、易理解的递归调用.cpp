### 解题思路
注意递归的返回true的条件，一定要考虑是叶子结点的情况
return 的结果是左子树和右子树递归结果的或，因为只要存在就是true
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
        return hasPathSumHelper(root,sum);
    }
    bool hasPathSumHelper(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        if(root->val==sum&&
        root->left==nullptr&&
        root->right==nullptr) return true;
        return  hasPathSum(root->left, sum-root->val)||
                hasPathSum(root->right, sum-root->val);
    }
};
```