### 解题思路
二叉树中序遍历迭代法的应用

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
        self.root = root
        self.stk = []

    def next(self) -> int:
        """
        @return the next smallest number
        """
        while self.root:
            self.stk.append(self.root)
            self.root = self.root.left
        if self.hasNext():
            top = self.stk.pop()
            self.root = top.right
            return top.val
            
        


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.root or self.stk:
            return True
        else:
            return False



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```