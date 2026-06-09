- 利用101题和104题的思想，直接就做出来了。
- 递归判断每个节点的左右子树是否满足：最大深度差<2，的条件。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->right),maxDepth(root->left))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (abs(maxDepth(root->left) - maxDepth(root->right)) <=1 ) && isBalanced(root->left) && isBalanced(root->right);
    }
};
```
