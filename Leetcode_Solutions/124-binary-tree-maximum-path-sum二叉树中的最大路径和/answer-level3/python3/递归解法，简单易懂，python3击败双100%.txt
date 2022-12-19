![image.png](https://pic.leetcode-cn.com/7bd0ed168aaebdf879043d6fee112c990828bc17f4f5bb48f20781f4f590823c-image.png)

核心思路：对每个节点，计算全局最大值，同时返回以当前节点作为根节点的最大和

```
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
      self.res = -float("inf")
      _ = self.dfs(root)
      return self.res
      
    def dfs(self, root):
      if (not root.left) and (not root.right):
        if root.val > self.res: self.res = root.val
        return root.val
      root_val = root.val
      curr_max = root.val
      if root.left and root.right:
        left_val = self.dfs(root.left)
        right_val = self.dfs(root.right)
        val = max(right_val, left_val)
        root_val += (val if val>0 else 0)
        curr_max += (0 if right_val < 0 else right_val)
        curr_max += (0 if left_val < 0 else left_val)
        self.res = max(curr_max, self.res)
        return root_val
      elif root.right:
        right_val = self.dfs(root.right)
        root_val = root.val + (0 if right_val < 0 else right_val)
        self.res = max(root_val, self.res)
        return root_val
      else:
        left_val = self.dfs(root.left)
        root_val = root.val + (0 if left_val < 0 else left_val)
        self.res = max(root_val, self.res)
        return root_val
```
