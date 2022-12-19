### 解题思路
此处撰写解题思路

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
        self.sta=[]
        self.root=root
        while(self.root):
            self.sta.append(self.root)
            self.root=self.root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """
        p = self.sta[-1]
        re = p.val
        self.sta.pop()
        ri = p.right
        while ri:
            self.sta.append(ri)
            ri = ri.left
        return re    


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.sta)>0



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```