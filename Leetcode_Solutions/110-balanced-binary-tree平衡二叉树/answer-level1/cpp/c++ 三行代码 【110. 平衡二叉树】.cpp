### 解题思路
子树返回自身深度，和是否是平衡树
根节点根据子树返回构造自己的状态

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
    bool isBalanced(TreeNode* root) {
        return balance(root)[0];
    }
    vector<int> balance(TreeNode* root) {
        if (!root) return {1, 0};
        auto lret = balance(root->left);
        auto rret = balance(root->right);
        return {lret[0]&&rret[0]&&abs(lret[1]-rret[1])<=1, max(lret[1], rret[1])+1};
    }
};
```