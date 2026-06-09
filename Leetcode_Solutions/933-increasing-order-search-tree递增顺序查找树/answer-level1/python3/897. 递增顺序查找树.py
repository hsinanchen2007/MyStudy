### 解题思路
参考官方 yield 用法

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(root):
            if root:
                #不断向下找寻具有左节点的结点
                yield from inorder(root.left)
                #当不存在左节点时，开始中序搜索过程
                yield root.val
                yield from inorder(root.right)
        ans = cur = TreeNode(None)
        for c in inorder(root):
            cur.right = TreeNode(c)
            cur = cur.right
        return ans.right
```