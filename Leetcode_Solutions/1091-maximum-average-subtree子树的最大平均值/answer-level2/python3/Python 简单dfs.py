![image.png](https://pic.leetcode-cn.com/eb5b77908cd0ad43ed04a04eeb93fb16c5c98f78b9fd8998bdc0f94d05919938-image.png)


```
from typing import List
class Solution:

    def solve(self, root: TreeNode  , ans: List[float]):
        if root is None:
            return (0, 0)   #(总和，节点总数)

        l, r = self.solve(root.left, ans), self.solve(root.right, ans)
        ans[0] = max(ans[0], (l[0] + r[0] + root.val) / (1 + l[1] + r[1]))
        return (l[0] + r[0] + root.val, (1 + l[1] + r[1]))

    def maximumAverageSubtree(self, root: TreeNode) -> float:
        ans = [0]
        self.solve(root, ans)
        return ans[0]
```
