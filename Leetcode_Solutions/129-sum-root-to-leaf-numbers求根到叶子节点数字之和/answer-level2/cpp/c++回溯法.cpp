

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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode* node, int item){
        if(!node) return;
        if(!node->left && !node->right) sum += item*10 + node->val;
        item = item*10 + node->val;
        dfs(node->left, item);
        dfs(node->right, item);
    }
};
```