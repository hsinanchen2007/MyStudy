直接看代码，有注释：
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def inorder(root): # 中序遍历，遍历的结果存入 self.order
            order = 0
            self.order = {}
            stack = []
            stack.append((root, False))
            while stack:
                root, visited = stack.pop()
                if not root:
                    continue
                if visited:
                    self.order[root] = order
                    order += 1
                else:
                    stack.append((root.right, False))
                    stack.append((root, True))
                    stack.append((root.left, False))
            return self.order
        order = inorder(root)
        node = root
        while node: # 转化为 leetcode 235，根据中序遍历的顺序来找最近公共父节点
            position_node = self.order[node]
            position_p, position_q = self.order[p], self.order[q]
            if position_node > position_p and position_node > position_q:
                node = node.left
            elif position_node < position_p and position_node < position_q:
                node = node.right
            else:
                return node
```
