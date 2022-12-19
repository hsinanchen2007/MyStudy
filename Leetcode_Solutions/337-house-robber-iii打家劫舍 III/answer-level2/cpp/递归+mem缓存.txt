### 解题思路
先递归，求得递归方程后
利用mem进行缓存，去除重复计算

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
    map<TreeNode*,int> maps;
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (maps.find(root) != maps.end()) {
            return maps[root];
        }
        int left = rob(root->left);
        int right = rob(root->right);
        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        if (root->left != nullptr) {
            ll = rob(root->left->left);
            lr = rob(root->left->right);
        }
        if (root->right != nullptr) {
            rl = rob(root->right->left);
            rr = rob(root->right->right);
        }
        int result = max(left + right, root->val + ll + lr + rl + rr);
        maps[root] = result;
        return result;
    }
};
```