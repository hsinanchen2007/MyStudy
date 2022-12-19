
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
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None: return True
        if p == None or q == None: return False
        if p.val != q.val:return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

```
```C++ []
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
    if (p == NULL && q == NULL) return true;
    if (q == NULL || p == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    
    }
};
```