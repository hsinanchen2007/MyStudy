```python []
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:return True
        if not p or not q: return False
        if p.val != q.val: return False
        return self.isSameTree(p.left,q.left) and self.isSameTree(p.right, q.right)
```
```c++ []
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {     
        if( p == NULL && !q) return true;
        if(!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
    }
};
```
