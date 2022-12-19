### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
    int maxvalue = INT32_MIN;

    int dfs(TreeNode *node)
    {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);
        maxvalue = max(maxvalue,node->val);
        maxvalue = max(maxvalue, node->val + left);
        maxvalue = max(maxvalue, node->val + right);
        maxvalue = max(maxvalue, node->val + left+right);

        return max(node->val,max(left + node->val, right + node->val));
    }

    int maxPathSum(TreeNode *root)
    {
        maxvalue = INT32_MIN;
        dfs(root);
        return maxvalue;
    }
};
```