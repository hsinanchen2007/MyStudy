### 解题思路
经典DFS 后序遍历

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
    TreeNode *dfs(TreeNode *node, int target)
    {
        if (node == nullptr) {
            return nullptr;
        }


        node->left = dfs(node->left, target);
        node->right = dfs(node->right, target);

        if (node->left == nullptr && node->right == nullptr && node->val == target) {
            return nullptr;
        }

        return node;
    }


    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        return dfs(root, target);
    }
};
```