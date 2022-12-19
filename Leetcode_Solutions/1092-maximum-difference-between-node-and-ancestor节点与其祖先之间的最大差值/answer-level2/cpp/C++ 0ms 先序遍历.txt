# 思路：
就一个节点来说所谓最大差值，就是**祖先的最大值或者最小值和自己的val的差值**。
只需要知道所有祖先可能的最大值和最小值，在遍历时携带传递即可。

# 代码：
```
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return result;
    }

private:
    int result = 0;
    void dfs(TreeNode* node, int up, int low) {
        if (node == nullptr) {
            return;
        }
        result = max(max(abs(node->val - up), abs(node->val - low)), result);
        up = max(node->val, up);
        low = min(node->val, low);
        dfs(node->left, up, low);
        dfs(node->right, up, low);
    }
};
```
