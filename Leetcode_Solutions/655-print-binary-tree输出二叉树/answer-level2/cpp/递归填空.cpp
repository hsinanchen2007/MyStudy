### 解题思路
1. 写一个height() 递归找到树的深度depth，然后根据题意，至多有width = 2^depth - 1 个节点
2. 初始化 res[depth][width],然后填充数字。
3. 按照 根节点在中间，左子树在左边，右子树在右边填充

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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if (root == NULL) {
            return res;
        }
        int depth = height(root);
        int width = pow(2, depth) - 1;
        vector<string> row(width, "");
        for (int i = 0; i < depth; i++) {
            res.push_back(row);
        }

        helper(root, 0, 0, width - 1, res);
        return res;
    }
private:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }

    void helper(TreeNode* node, int depth, int start, int end, vector<vector<string>>& vec) {
        if (node == NULL) {
            return;
        }
        int mid = start + (end - start) / 2;
        vec[depth][mid] = to_string(node->val);
        if (node->left) {
            helper(node->left, depth + 1, start, mid - 1, vec);
        }
        if (node->right) {
             helper(node->right, depth + 1, mid + 1, end, vec);
        }
    }
};
```