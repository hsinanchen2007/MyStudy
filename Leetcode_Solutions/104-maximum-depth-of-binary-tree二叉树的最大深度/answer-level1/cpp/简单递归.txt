### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    int dfs(TreeNode* node, int depth,int result);
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
        if (root == nullptr)return 0;
        result = dfs(root, result,result);
        return result;
    }
};

int Solution::dfs(TreeNode* node, int depth,int result)
{
    depth++;
    result = depth > result ? depth : result;
    if (node->left != nullptr) result = dfs(node->left, depth, result);
    if (node->right != nullptr)result = dfs(node->right, depth, result);
    return result;
}

```