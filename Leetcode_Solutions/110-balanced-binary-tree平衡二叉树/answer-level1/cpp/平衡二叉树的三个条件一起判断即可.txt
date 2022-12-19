1. 左子树高度与右子树高度差小于等于1
2. 左子树是平衡的
3. 右子树是平衡的

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

int depth(TreeNode *t)
{
    if(!t)return 0;

    int left=depth(t->left);
    int right=depth(t->right);

    return left>right?left+1:right+1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)return true;

        return ((abs(depth(root->left)-depth(root->right)))<=1&&isBalanced(root->left)&&isBalanced(root->right));
    }
};
```