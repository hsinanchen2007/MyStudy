#### 算法思想：
- 如果二叉搜索树为空树，用 val 构造二叉树节点作为根节点并返回。
- 否则，搜索新结点的插入位置，沿子结点关系向下：遇到应该走向左子树而左子树为空，或者应该走向右子树而右子树为空时，就是找到了新字典项的插入位置，构造新结点并完成实际插入。之后，返回根节点。
#### 算法实现：
```Python []
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None:
            root = TreeNode(val)
            return root
        p = root
        while True:
            if val < p.val:
                if p.left is None:
                    p.left = TreeNode(val)
                    return root
                p = p.left
            else:
                if p.right is None:
                    p.right = TreeNode(val)
                    return root
                p = p.right
        
#         if root is None:
#             root = TreeNode(val)
#             return root
#         par = None
#         p = root
#         while p is not None:
#             if val < p.val:
#                 par = p
#                 p = p.left
#             else:
#                 par = p
#                 p = p.right
        
#         p = TreeNode(val)
#         if val < par.val:
#             par.left = p
#         else:
#             par.right = p
#         return root
```
#### 复杂度分析：
- 时间复杂度：树的高度，即 $O(logN)$，N 为书中节点数。当树畸形时，可能为 $O(N)$。
- 空间复杂度：$O(1)$。
