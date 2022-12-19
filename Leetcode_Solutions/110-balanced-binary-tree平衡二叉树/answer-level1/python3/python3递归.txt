### 解题思路
**Q：如果左右子树是平衡的，那么如何判断该树是平衡的？**
A:计算左右子树的深度，相差小于1就好

**Q：如何计算子树的深度？**
A：如果计算出子树的左子树深度为m，右子树的深度为n，则该子树的深度为max(m,n)+1

以上的 “如果左右子树是平衡的” “如果计算出子树的左子树.......”
需要使用递归来实现

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root is None:
            return True
        # 计算子树的深度
        def count_depth(node):
            if node is None:
                return 0
            if node.left is None and node.right is None:
                return 1
            return max(count_depth(node.left),count_depth(node.right))+1
        # 检查是否平衡
        def check_balance(node):
            if node is None:
                return True
            if node.left is None and node.right is None:
                return True     
            left_depth=count_depth(node.left)
            right_depth=count_depth(node.right)
            a=abs(left_depth-right_depth)<=1
            return a and check_balance(node.left) and check_balance(node.right)

        return check_balance(root)

```