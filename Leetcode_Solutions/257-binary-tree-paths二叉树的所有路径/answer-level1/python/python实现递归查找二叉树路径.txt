### 解题思路
此题就是一个深度优先的遍历，因此只需要后序遍历二叉树，可用一个栈存储访问路径，访问到叶子结点时输出栈中内容即可。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    stack=[]
    result=[]
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.result=[]
        self.stack=[]
        self.visit(root)
        return self.result

    def visit(self,root):
        if root is None:
            return
        self.stack.append(root)
        if root.left is not None:
            self.visit(root.left)
        if root.right is not None:
            self.visit(root.right)
        
        if root.left is None and root.right is None:
            self.result.append('->'.join(map(lambda x:str(x.val),self.stack)))
        self.stack.pop()
        

```