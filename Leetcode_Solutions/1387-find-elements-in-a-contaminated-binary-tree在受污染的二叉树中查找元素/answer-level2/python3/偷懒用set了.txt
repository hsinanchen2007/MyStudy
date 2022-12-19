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

class FindElements:

    def __init__(self, root: TreeNode):
        self.val_set = set()
        if root:
            root.val = 0
            self.val_set.add(0)
        if root.left:
            self.modify(root.left, 0, 1)
        if root.right:
            self.modify(root.right, 0, 2)
        self.root = root

    
    def modify(self, root, x, b):
        root.val = 2 * x + b
        self.val_set.add(root.val)
        if root.left:
            self.modify(root.left, root.val, 1)
        if root.right:
            self.modify(root.right, root.val, 2)


    def find(self, target: int) -> bool:
        return target in self.val_set
        
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
```