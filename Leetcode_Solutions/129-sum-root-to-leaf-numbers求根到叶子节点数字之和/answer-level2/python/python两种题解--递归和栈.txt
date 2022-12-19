### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res = 0

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        #递归解法
        if not root:
            return 0
        
        def SolutionS(node,sums):
            if node:
                sums += str(node.val)
                SolutionS(node.right, sums)
                SolutionS(node.left, sums)
                if node.left == None and node.right == None:
                    self.res += int(sums)

        SolutionS(root, '')
        return self.res

        #使用栈的解法
        if not root:
            return 0

        stack = [(root,str(root.val))]
        while stack:
            node, num = stack.pop()
            if node.right == None and node.left == None:
                self.res += int(num)
                continue
            if node.left:
                stack.append((node.left,num + str(node.left.val)))
            if node.right:
                stack.append((node.right,num + str(node.right.val)))

        return self.res
```