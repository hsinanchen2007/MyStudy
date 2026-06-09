## 二叉树递归套路解法

对于需要向左右子节点索取信息的问题，可以使用如下递归套路。

1、对每个节点进行可能性分析，判断是return false 还是return true。

2、递归实现功能。

if 根节点满足某种条件

return 递归(左子树) && 递归(右子树)

return (递归(左子树) || 递归右子树) （其中一个满足条件即可）

return false

本题对每个节点要求左右子树都为平衡树，即左右子树的高度相差小于2。
```python []
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        if abs(self.maxdepth(root.left) - self.maxdepth(root.right)) < 2:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
        return False
    def maxdepth (self, root:TreeNode) -> int:
        if not root: return 0
        return max(self.maxdepth(root.left) + 1, self.maxdepth(root.right) + 1 )
```

```C++ []
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if (abs(maxdepth(root->left)-maxdepth(root->right)) < 2){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
    
    int maxdepth(TreeNode* root){
        if(root == NULL) return 0;
        return max(maxdepth(root->left)+1, maxdepth(root->right)+1);
    }
    
};
```
