### 解题思路
1.普通迭代
2.先序遍历（将空节点也记录）
3.DFS
4.BFS

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
#递归
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q:
            return True
        elif p and q:
            return p.val == q.val and self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
        else:
            return False
#先序遍历：注意这个先序遍历也记录空节点
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        def preorder(root):
            if not root:
                return [None]
            else:
                return [root.val] +preorder(root.left)+preorder(root.right)
        return preorder(p)==preorder(q)
#DFS
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        stack = [(q, p)]
        while stack:
            a, b = stack.pop()
            if not a and not b:
                continue
            if a and b and a.val == b.val:
                stack.append((a.left, b.left))
                stack.append((a.right,b.right))
            else:
                return False
        return True
#BFS
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        queue = deque([(q, p)])
        while queue:
            a, b = queue.popleft()
            if not a and not b:
                continue
            if a and b and a.val == b.val:
                queue.append((a.left, b.left))
                queue.append((a.right,b.right))
            else:
                return False
        return True
```