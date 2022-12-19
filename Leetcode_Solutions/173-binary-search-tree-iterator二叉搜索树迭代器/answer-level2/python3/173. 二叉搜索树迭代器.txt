> 11.26 python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.back_root = root
        while self.back_root:
            self.stack.insert(0, self.back_root)
            self.back_root = self.back_root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        top = self.stack.pop(0)
        self.back_root = top.right
        while self.back_root:
            self.stack.insert(0, self.back_root)
            self.back_root = self.back_root.left
        return top.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.stack:
            return True
        else:
            return False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```