### 解题思路
1. 迭代，和前序遍历的迭代差不多，但是在迭代的时候需要进行拼接操作
2. 前序遍历的递归形式，每当遍历一个节点就需要拼接该点

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
        # if not root:
        #     return None

        # while root:
        #     if root.left:
        #         cur = root.left
        #         while cur.right:
        #             cur = cur.right   # 循环一直寻找到左子树的最右节点
        #         cur.right = root.right  # 将右子树挂接在左子树的最右节点
        #         root.right = root.left  # 将左子树挂在右子树的节点上
        #         root.left = None    # 将左子树节点置为空
        #     root = root.right  # 下一个节点
        # return root

        def helper(r):
            if not r:
                return None
            helper(r.left)
            helper(r.right)
            if r.left:
                tail = r.left
                while tail and tail.right:
                    tail = tail.right
                tail.right = r.right
                r.right = r.left
                r.left = None
            return
        helper(root)

```