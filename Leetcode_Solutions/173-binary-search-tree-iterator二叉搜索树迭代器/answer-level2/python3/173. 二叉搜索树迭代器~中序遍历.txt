### 解题思路
这道题直接使用中序遍历，用列表记录遍历结果
然后就是对列表的了：
lst.pop(0) == next()操作
if len(lst) == hasnext()操作

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
        self.stack = []
        self.lst = []
        while root or self.stack:
            while root:
                self.stack.append(root)
                root = root.left
            root = self.stack.pop()
            self.lst.append(root.val)
            root = root.right

    def next(self) -> int:
        """
        @return the next smallest number
        """
        return self.lst.pop(0)


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if len(self.lst) > 0:
            return True
        else:
            return False



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```