### 解题思路
此处撰写解题思路

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
    bool ans = true;  //首先赋予true
    int depth(TreeNode* root)
    {
        if(root == NULL) return 0;  //如果节点为空，深度为0
        int ld = depth(root -> left);
        int rd = depth(root -> right);
        if(abs(ld - rd) > 1) ans = false;  //若左子树与右子树的高度相差大于1，结果为false
        return max(ld, rd) + 1;  //返回当前节点的高度
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return ans;
        int height = depth(root);
        return ans;
    }
};
```