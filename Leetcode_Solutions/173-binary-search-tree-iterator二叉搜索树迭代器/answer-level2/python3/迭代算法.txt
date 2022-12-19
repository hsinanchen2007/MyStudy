```
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.curr = root
        

    def next(self) -> int:
        """
        @return the next smallest number
        """
        while self.curr:
            self.stack.append(self.curr)
            self.curr = self.curr.left
        n = self.stack.pop()
        self.curr = n.right
        return n.val
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.curr or self.stack
```
