## 二叉树递归套路解法：

对于需要向左右子节点索取信息的问题，可以使用如下递归套路。

1、对每个节点进行可能性分析，判断是return false 还是return true。

2、递归实现功能。

if 根节点满足某种条件

+ return 递归(左子树) && 递归(右子树) 

+ return (递归(左子树) || 递归右子树) （其中一个满足条件即可）

return false

```python []
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None: return True
        return self.fun(root.left, root.right)
    def fun (self, l_root: TreeNode, r_root: TreeNode) -> bool:
        if l_root == None and r_root == None: return True
        if l_root == None or r_root == None: return False
        if l_root.val == r_root.val: 
            return self.fun(l_root.left, r_root.right) and self.fun(l_root.right, r_root.left)
```
```C++ []
class Solution {
public:
    bool isSymmetric(TreeNode* root){
    if (root == NULL) return true;
    return fun(root->left, root->right);
}

    bool fun(TreeNode* l_root, TreeNode* r_root)
    {
        if (l_root == NULL && r_root == NULL) return true;
        if (l_root == NULL || r_root == NULL) return false;
        if (l_root->val == r_root->val)
            return  fun(l_root->left,  r_root->right) && fun(l_root->right, r_root->left);
        return false;
    }

};
```


