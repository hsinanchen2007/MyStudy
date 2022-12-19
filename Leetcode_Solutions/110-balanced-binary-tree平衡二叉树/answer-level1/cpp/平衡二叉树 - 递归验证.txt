### 解题思路
1. 根据平衡二叉树定义，判断根节点是否满足二叉树定义，若不满足返回`false`；
2. 若满足，递归判断根节点左右子树是否满足定义（即对左右子树做`1.`）
3. 若`1.`和`2.`不返回，则返回`true`

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
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int left_depth = 0, right_depth = 0;
        if(root->left) left_depth = dfs(root->left);
        if(root->right) right_depth = dfs(root->right);
        return max(left_depth, right_depth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left_depth = 0, right_depth = 0;
        left_depth = dfs(root->left);
        right_depth = dfs(root->right);
        if(abs(left_depth - right_depth) > 1) return false;
        if(isBalanced(root->left) == false) return false;
        if(isBalanced(root->right) == false) return false;
        return true;
    }
};
```