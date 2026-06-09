![image.png](https://pic.leetcode-cn.com/3291b43898ad9705cf106c5916b4854574e1b28dee5d7f1643d1a261eea89d4c-image.png)


```
from typing import List
class Solution:

    def dfs(self, root, parent, grandpa, ans: List[int]):
        if root is None:
            return

        if grandpa % 2 == 0:
            ans[0] += root.val

        self.dfs(root.left, root.val, parent, ans)
        self.dfs(root.right, root.val, parent, ans)


    def sumEvenGrandparent(self, root: TreeNode) -> int:
        ans = [0]
        self.dfs(root, 1, 1, ans)
        return ans[0]
```
