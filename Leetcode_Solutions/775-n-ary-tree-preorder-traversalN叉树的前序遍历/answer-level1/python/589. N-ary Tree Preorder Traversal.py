跟二叉树遍历其实是差不多的
root -> left -> right
这里是N个结点 就是children嘛, 但是也是有顺序的

模型确定的是 root -> children
                      递归 -> root -> children
```
class Solution(object):
    def __init__(self):
        self.L = []

    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is not None:
            self.tranverse(root)
            
        return self.L

    def tranverse(self, node):
        if node is not None:
            self.L.append(node.val)
            if node.children is not None:
                for child in node.children:
                    self.tranverse(child)
```
