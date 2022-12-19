如下, 使用stack缓存部分中序遍历的结果
```python
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        if root:
            # node traversaled
            self.stack.append((root, False))
            self.update()
    
    def update(self):
        while self.stack and not self.stack[-1][-1]:
            node, used = self.stack.pop()
            if node.right:
                self.stack.append((node.right, False))
            self.stack.append((node, True))
            if node.left:
                self.stack.append((node.left, False))
    


    def next(self) -> int:
        """
        @return the next smallest number
        """
        res, _ = self.stack.pop()
        self.update()
        return res.val


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return True if self.stack else False
```