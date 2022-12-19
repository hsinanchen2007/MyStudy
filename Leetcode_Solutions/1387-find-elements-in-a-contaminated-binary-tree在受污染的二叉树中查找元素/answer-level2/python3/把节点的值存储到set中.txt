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

class FindElements:

    def __init__(self, root: TreeNode):
        
        self._hashset = {0,}
        root.val = 0
        
        def __dfs(node):
            if node.left:
                node.left.val = node.val*2 + 1
                self._hashset.add(node.left.val)
                __dfs(node.left)
            if node.right:
                node.right.val = node.val*2 + 2
                self._hashset.add(node.right.val)
                __dfs(node.right)
        

        __dfs(root)

    def find(self, target: int) -> bool:
        return target in self._hashset
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
```