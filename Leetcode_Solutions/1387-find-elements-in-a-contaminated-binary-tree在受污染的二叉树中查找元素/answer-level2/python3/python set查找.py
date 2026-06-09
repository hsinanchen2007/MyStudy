### 解题思路
题意直接生成代码，用set来储存放置的数方便查找

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
        self.s = set()
        if root:
            root.val = 0
            
        def dfs(root):
            if not root:
                return
            self.s.add(root.val)
            if root.left:
                root.left.val = root.val*2+1
                dfs(root.left)
            if root.right:
                root.right.val = root.val*2+2
                dfs(root.right)
        dfs(root)

    def find(self, target: int) -> bool:
        return target in self.s

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
```