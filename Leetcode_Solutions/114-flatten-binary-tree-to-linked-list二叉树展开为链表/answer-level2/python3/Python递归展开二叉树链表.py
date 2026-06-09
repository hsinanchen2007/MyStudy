### 解题思路
展开的链表为前序
即root-left-right
递归地把每个子树都展开成链表,并通过辅助函数返回了每个子树的结尾(方便相连)
默认把原二叉树结构的right当做链表的next

执行用时 :36 ms, 在所有 python3 提交中击败了96.84% 的用户
内存消耗 :12.8 MB, 在所有 python3 提交中击败了100.00%的用户
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.returnEnd(root)
    def returnEnd(self,root):
        if not root: return None
        if not root.left and not root.right: return root
        if not root.left: return self.returnEnd(root.right)
        if not root.right: 
            root.right = root.left
            root.left = None
            return self.returnEnd(root.right)
        res = self.returnEnd(root.right)
        self.returnEnd(root.left).right = root.right
        root.right = root.left
        root.left = None
        return res
```