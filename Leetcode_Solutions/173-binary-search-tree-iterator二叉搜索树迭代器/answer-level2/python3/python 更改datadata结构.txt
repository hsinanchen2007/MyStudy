```
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.root = root

    def next(self) -> int:
        """
        @return the next smallest number
        """
        # 当前节点的上一个值
        pre = None
        curr = self.root
        while curr.left is not None:
            pre = curr
            curr = curr.left
        # 若节点未移动，头节点改变
        if pre == None:
            self.root = curr.right
        # 上一节点的left值改变
        else:
            if curr.right is not None:
                pre.left = curr.right
            else:
                pre.left = None       
        
        return curr.val

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        if self.root is not None:
            return True
        else:
            return False
```
