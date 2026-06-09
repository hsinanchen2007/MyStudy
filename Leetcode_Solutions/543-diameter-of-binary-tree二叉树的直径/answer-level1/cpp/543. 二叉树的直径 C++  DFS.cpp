### 解题思路
DFS
1）取每个子树的路径和与最大值比
2）同时向上层返回该子树左分支和右分支的最大值

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
    int result = 0;
    int dfs(TreeNode *node)
    {
        if (node == nullptr) {
            return 0;
        }

        int leftvalue = dfs(node->left);
        int rightvalue = dfs(node->right);
        result = max(result, leftvalue + rightvalue + 1);

        return max(leftvalue, rightvalue) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        result = 1;
        dfs(root);
        return result-1;
    }
};
```