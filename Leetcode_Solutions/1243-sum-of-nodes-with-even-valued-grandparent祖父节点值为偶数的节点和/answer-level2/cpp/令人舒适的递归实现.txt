### 解题思路

1. 定义一个变量`ans`存返回结果，如果`root`节点的值是偶数，将它所有的孙子节点的值加入`ans`
2. 如果`root`有左子树，对左子树进行上述操作，如果root有右子树，对右子树进行上述操作

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
    int ans = 0;
    void dfs(TreeNode* root){
        if(root->val%2 == 0){
            if(root->left){
                if(root->left->left) ans += root->left->left->val;
                if(root->left->right) ans += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) ans += root->right->left->val;
                if(root->right->right) ans += root->right->right->val;
            }
        }
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```