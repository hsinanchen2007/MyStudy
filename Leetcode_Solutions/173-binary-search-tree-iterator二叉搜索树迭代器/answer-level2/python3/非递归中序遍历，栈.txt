```
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.current = root
        while self.current:
            self.stack.append(self.current)
            self.current = self.current.left
        

    def next(self) -> int:
        """
        @return the next smallest number
        """
        if self.stack:
            top = self.stack.pop()
            self.current = top.right
            while self.current:
                self.stack.append(self.current)
                self.current = self.current.left
            return top.val
        return None
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.stack:
            return True
        else:
            return False
```
