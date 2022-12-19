### 解题思路
对于一个节点来说，先求得左子树高度，在求右子树高度，如果两者绝对值大于1，结果为false，本节点的高度为左子树高度和右子树高度的最大值加1；
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
    bool ans = true;
    int depth(TreeNode* root)
    {
        if(root == NULL) return 0;
        int ld = depth(root -> left);
        int rd = depth(root -> right);
        if(abs(ld - rd) > 1) ans = false;
        return max(ld, rd) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int x = depth(root);
        return ans;
    }
};
```