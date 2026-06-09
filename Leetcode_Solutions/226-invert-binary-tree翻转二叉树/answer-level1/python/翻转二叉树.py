### 解题思路
1.深度优先搜索（非递归）
先判断边界条件，是否为空，是否有子树，然后深度遍历树的各个节点，翻转当前探索节点的左右子树
2.BFS
3.递归
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
#DFS
        if root == None:
            return None
        if root.left == None and root.right == None:
            return root
        stack = []
        stack.append(root)

        while stack:
            node = stack.pop()
            if node:
                temp = node.left
                node.left = node.right
                node.right = temp
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return root
#BFS
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None:
            return None
        if root.left == None and root.right == None:
            return root
        queue = deque([root])

        while queue:
            node = queue.popleft()
            if node:
                temp = node.left
                node.left = node.right
                node.right = temp
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return root
#递归
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return
        root.left,root.right = self.invertTree(root.right),self.invertTree(root.left)
        return root
```