```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator:

    def __init__(self, root: TreeNode):
        self.s = []
        while root: self.s[len(self.s):], root = [root], root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        r, root = self.s[-1], self.s.pop().right
        while root: self.s[len(self.s):], root = [root], root.left
        return r.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return bool(self.s)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```
- 模拟中序遍历的迭代过程，使用堆栈 `self.s` 进行深度优先搜索
- 空间复杂度为 O(树的高度)
- 平均时间复杂度 = 循环总次数（N） / 迭代器长度（N） = O(1)

```python
from itertools import chain

class BSTIterator:

    def __init__(self, root: TreeNode):
        def gen(root): yield from chain(gen(root.left), [root.val], gen(root.right)) if root else ()
        self.iter, self.len = gen(root), 0
        for _ in gen(root): self.len += 1

    def next(self) -> int:
        """
        @return the next smallest number
        """
        self.len -= 1
        return next(self.iter)

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return bool(self.len)
```
- 平均时空复杂度： O(1)，O(1)