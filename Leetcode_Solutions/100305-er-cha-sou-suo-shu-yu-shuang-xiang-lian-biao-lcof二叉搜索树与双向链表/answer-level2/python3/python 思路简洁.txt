```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return
        def ldr(root):
            if not root:
                return []
            return ldr(root.left)+[root]+ldr(root.right)
        sort_node=ldr(root)     #中序遍历搜索二叉树，节点存在列表 sort_node 中
        n=len(sort_node)
        for i in range(n):      # 遍历该列表，重新调整指针
            if i<n-1:
                sort_node[i].left=sort_node[i-1]
                sort_node[i].right=sort_node[i+1]
            else:
                sort_node[i].left=sort_node[i-1]
                sort_node[i].right=sort_node[0]
        return sort_node[0]
```
