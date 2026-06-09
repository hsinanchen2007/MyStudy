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
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        #递归解法
        if not root:
            return 0
        
        def SolutionS(node,sums):
            if node:
                sums += node.val
                SolutionS(node.right, sums)
                SolutionS(node.left, sums)
                if node.left == None and node.right == None:
                    if sums == sum:
                        self.res += 1        

        SolutionS(root, 0)
        return self.res

        #使用栈的解法
        if not root:
            return 0

        stack = [(root,root.val)]
        while stack:
            node, num = stack.pop()
            if node.right == None and node.left == None:
                if num == sum:
                    self.res += 1
                continue
            if node.left:
                stack.append((node.left,num + node.left.val))
            if node.right:
                stack.append((node.right,num + node.right.val))

        return self.res            






















```