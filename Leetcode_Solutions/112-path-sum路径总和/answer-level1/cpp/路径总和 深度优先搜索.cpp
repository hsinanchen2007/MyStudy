### 解题思路
此处撰写解题思路

1. 当结点是叶子结点时，判断是否匹配
2. 当结点是非叶子结点时，计算到当前深度时所经过的路径中左右结点的和，并继续往下递归，递归返回的结果是左子树或者右子树匹配。


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
        if (root == nullptr)
            return false;

        auto cur_sum = 0;
        return DFS(root, cur_sum, sum);
    }

    bool DFS(TreeNode* node, int last_sum, const int& sum) {
        auto cur_sum = last_sum + node->val;

        if (node->left == nullptr && node->right == nullptr) {
            return cur_sum == sum;
        }

        bool left = false;
        if (node->left != nullptr)
            left = DFS(node->left, cur_sum, sum);

        bool right = false;
        if (node->right != nullptr)
            right = DFS(node->right, cur_sum, sum);

        return left || right;
    }
};
```