Python3

一个有效的二叉搜索树，满足一下三个条件：
1.左子树的节点值均小于当前节点值 -> max_val(root.left) < root.val
2.右子树的节点值均大于当前节点值 -> min_val(root.right) > root.val
3.左右子树均为BST -> l and r,其中l = self.isValidBST(root.left) ；r = self.isValidBST(root.right)
因此定义函数
func:= isValidBST
input: root
return: 条件1 and 条件2 and 条件3

除此之外，定义两个辅助函数，计算树的最大节点和最小节点。





```
class Solution:
    """给定一个二叉树，判断其是否是一个有效的二叉搜索树
    """
    def isValidBST(self, root: TreeNode) -> bool:
        if not root: return True  # 根节点为空, 返回True
        l = self.isValidBST(root.left)  # 左子树是否为BST
        r = self.isValidBST(root.right)  # 右子树是否为BST
        return l and r and self.max_val(root.left) < root.val and self.min_val(root.right) > root.val

    def min_val(self, root: TreeNode) -> int:
        """给定一个二叉树，返回树的节点最小值
        """
        if not root: return float('inf')  # 空树的最小节点为正无穷
        l = self.min_val(root.left)  # 左子树的最小值
        r = self.min_val(root.right)  # 右子树的最小值
        return min(root.val, l, r)
    
    def max_val(self, root: TreeNode) -> int:
        """给定一个二叉树，返回树的节点最大值
        """
        if not root: return float('-inf')  # 空树的最大节点为负无穷
        l = self.max_val(root.left)  # 左子树的最小值
        r = self.max_val(root.right)  # 右子树的最小值
        return max(root.val, l, r)
```
