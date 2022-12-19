1. 先遍历结构和数值，对比看结果。注意输入特例：[ ] [1]
2. 
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.a = []

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        self.leftOrder(root.left)
        left = self.a
        self.a = []

        self.rightOrder(root.right)
        right = self.a
        return left == right


    def leftOrder(self, root):
        if not root:
            self.a.append('a')
            return
        self.a.append(root.val)
        self.leftOrder(root.left)
        self.leftOrder(root.right)
    def rightOrder(self, root):
        if not root:
            self.a.append('a')
            return
        self.a.append(root.val)
        self.rightOrder(root.right)
        self.rightOrder(root.left)
```
2. 递归实现：比较left.left=right.tight和left.right=right.left,递归的终止条件是都为空，有一个为空，两个val不相等
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.a = []

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def dfs(p, q):
            if type(p)!=type(q):
                return False
            if not (p and q):
                return True
            if p.val!=q.val:
                return False
            return dfs(p.left, q.right) and dfs(p.right, q.left)
        return dfs(root.left, root.right)
        
```

3. 递归思想都可以用迭代实现
```
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.a = []

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def check(p, q):
            if not p and not q:
                return True
            if type(p)!=type(q):
                return False
            if p.val!=q.val:
                return False
            return True
        tmpList = [(root.left, root.right)]
        while tmpList:
            p, q = tmpList.pop(0)
            if not check(p,q):
                return False
            if p:
                tmpList.append((p.left, q.right))
                tmpList.append((p.right, q.left))
        return True
```
