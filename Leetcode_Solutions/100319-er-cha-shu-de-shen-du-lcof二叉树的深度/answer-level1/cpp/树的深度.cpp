
这道题目很直观，就是求深度
思路:
如果我们知道了左子树和右子树的深度，那么在加上根的高度1，就是
树的深度，左子树和右子树的深度由递归求解

### 代码

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return l >= r ? l + 1 : r + 1;
    }
};
```