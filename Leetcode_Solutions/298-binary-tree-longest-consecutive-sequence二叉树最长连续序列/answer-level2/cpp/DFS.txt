### 解题思路

DFS

### 代码

```cpp
class Solution {
private:
    int maxL = 0;
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root, 1);
        return maxL;
    }
    
    void dfs(TreeNode* node, int level) {
        if(node == nullptr) {
            return;
        }
        
        maxL = max(maxL, level);
        
        if(node->left && node->left->val == node->val + 1) 
            dfs(node->left, level + 1);
        else
            dfs(node->left, 1);                                 // 包含左子树为空的情形
        
        if(node->right && node->right->val == node->val + 1)
            dfs(node->right, level + 1);
        else
            dfs(node->right, 1);                                // 包含右子树为空的情形
    }
};
```