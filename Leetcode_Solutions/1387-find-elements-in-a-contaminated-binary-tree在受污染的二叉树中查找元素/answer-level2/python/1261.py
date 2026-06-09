### 解题思路
1、第一次没有用set()集合，find函数无法传入root参数；
2、使用set后，则可以直接判断target是否在set集合中，实现较简单。

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
        self.vals = set()
        def tree(node, val):
            node.val = val
            self.vals.add(node.val)
            if node.left is not None:
                node.left.val = node.val * 2 + 1
                tree(node.left, node.left.val)
            if node.right is not None:
                node.right.val = node.val * 2 + 2
                tree(node.right, node.right.val)
        tree(root, 0)

    def find(self, target: int) -> bool:
        if target in self.vals:
            return True
        else:
            return False


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
```