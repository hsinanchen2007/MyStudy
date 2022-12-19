中序遍历树,挨个比较值的大小.
python yield真方便...

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def yieldTree(tree: TreeNode):
    if (tree.left):
        for i in yieldTree(tree.left):
            yield i
    yield tree.val
    if(tree.right):
        for i in yieldTree(tree.right):
            yield i

class Solution:            
    def isValidBST(self, root: TreeNode) -> bool:
        if root is None:
            return True
        num = -2147483649
        for i in yieldTree(root):
            if num >= i:
                return False
            num = i
        return True
```
