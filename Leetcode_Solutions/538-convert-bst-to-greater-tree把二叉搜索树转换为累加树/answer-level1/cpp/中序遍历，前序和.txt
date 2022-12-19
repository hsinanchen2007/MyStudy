### 解题思路
该题题意不太明确，主要是求在中序遍历情况下，该结点右边部分所有节点的和
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
    TreeNode* convertBST(TreeNode* root) {
        int pre_sum = 0;
        dfs(root, pre_sum);
        return root;
    }

    void dfs(TreeNode* root, int& pre_sum) {
        if (root == nullptr) {
            return;
        }
        dfs(root->right, pre_sum);
        root->val += pre_sum;
        pre_sum = root->val;
        dfs(root->left, pre_sum);
    }
};
```