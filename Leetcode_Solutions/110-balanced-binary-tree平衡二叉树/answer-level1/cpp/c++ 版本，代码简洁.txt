# 思路：
- 对当前节点，分别求解左子树和右子树的深度，判断左右子树的高度差是否<=1。
- 利用了104题中求解二叉树的深度的方法
- 然后再对当前节点的左节点和右节点做同样操作。

`执行用时 :20 ms, 在所有 C++ 提交中击败了82.38% 的用户
内存消耗 :17.1 MB, 在所有 C++ 提交中击败了78.21%的用户`

```c++ 
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int d = abs(depth(root->left)-depth(root->right)); //当前节点的左右子树的高度差
        
        return (d<=1) && (isBalanced(root->left)) && (isBalanced(root->right));
    }
    
    // 求解二叉树深度（104题）
    int depth(TreeNode* node)
    {
        if(node ==NULL) return 0;
        return max( depth(node->left), depth(node->right) )+1;
    }
    
};
```
