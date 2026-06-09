思路: 中序遍历, 在巧妙利用栈来实现
```
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        curr = root
        while curr:
            self.stack.append(curr)
            curr = curr.left
        

    def next(self) -> int:
        """
        @return the next smallest number
        """
        node = self.stack.pop()
        
        curr = node.right
        while curr:
            self.stack.append(curr)
            curr = curr.left
        
        return node.val
        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) != 0
```
