![image.png](https://pic.leetcode-cn.com/f9ae52176cabb5a1fd2baad244309693f2c1dbec4f11af25b8b9bf529e1ba27d-image.png)

```
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
      if not root: return root
      self.prev = None
      self.dfs(root)
      while root.left:
        root = root.left
      self.prev.right = root
      root.left = self.prev
      return root

    def dfs(self, root):
      if not root: return
      self.dfs(root.left)
      if self.prev:
        self.prev.right = root
        root.left = self.prev
      self.prev = root
      self.dfs(root.right)
```
