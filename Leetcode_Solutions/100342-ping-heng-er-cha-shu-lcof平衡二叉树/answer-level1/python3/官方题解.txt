**难点在于为何要用max(self.height(root.left),self.height(root.right))**
首先是判断整体左右子树的平衡，如果高度差大于1，就直接返回错误，这里在比较时要分别计算左右子树中左右孩子最深的深度，故在height函数中采用max取最大值进行比较。
如果满足高度差小于1，则进入第二层子树进行重复判断，重复以上操作即可。
![image.png](https://pic.leetcode-cn.com/ce4cab928a4ba9cb237b37b90d7194eec7a9856c717799f875215c58ee8f11dc-image.png)


```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root: return True
        if (abs(self.height(root.left) - self.height(root.right)) > 1):
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
    def height(self,root):
        if not root: return 0
        return 1+max(self.height(root.left),self.height(root.right))
```
