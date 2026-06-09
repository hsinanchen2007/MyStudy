内存超过100%
时间差不多都是超过95%
非递归思路：中序遍历，注意使用一个哨兵节点来处理记录最左节点的麻烦
递归：返回当前root变成单向链表后的头节点和为节点
思路：三段处理，然后接起来。将root的左右节点处理完后，root左节点处理后单向链表的尾节点的右节点指向root，root的左节点置空，同时把root的右节点指向右节点处理后单向链表的头节点。
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        # def helper(root):
        #     if not root:
        #         return None, None
        #     if not root.left and not root.right:
        #         return root, root
        #     lh = rt = root
        #     if root.left:
        #         lh, lt = helper(root.left)
        #         lt.right = root
        #         root.left = None
        #     if root.right:
        #         rh, rt = helper(root.right)
        #         root.right = rh
        #     return lh, rt
        # return helper(root)[0]
        from collections import deque
        if root:
            stack = deque()
            cur = root
            # 哨兵节点，避免记录第一个cur的麻烦
            head = TreeNode(-1)
            prev = head
            while cur or stack:
                while cur:
                    stack.append(cur)
                    cur = cur.left
                cur = stack.pop()
                prev.right = cur
                cur.left = None
                prev = cur
                cur = cur.right
            return head.right
```
