### 解题思路
如题

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        # self.root = root
        self._res = []
        __stack =[(root, False)]
        while __stack:
            __node, __flag = __stack.pop()
            if __node:
                if __flag:
                    self._res.append(__node.val)
                else:
                    __stack.append((__node.left, False))
                    __stack.append((__node, True))
                    __stack.append((__node.right, False))

        

    def next(self) -> int:
        """
        @return the next smallest number
        """
        return self._res.pop()

        

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return True if self._res else False
        


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```