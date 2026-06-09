![image.png](https://pic.leetcode-cn.com/b13ad97f7fac916bfefab8509c3a14cff1588fbfb8e3b4e2cbd9cef48933d229-image.png)


```
'''
中序遍历然后两个列表进行归并
'''

from typing import List
class Solution:

    def dfs(self, root, path):
        if root is None:
            return

        self.dfs(root.left, path)
        path.append(root.val)
        self.dfs(root.right, path)

    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        l1, l2 = [], []
        self.dfs(root1, l1)
        self.dfs(root2, l2)

        i, j = 0, 0
        ans = []
        while i < len(l1) and j < len(l2):
            if l1[i] < l2[j]:
                ans.append(l1[i])
                i += 1
            else:
                ans.append(l2[j])
                j += 1

        if i < len(l1):
            ans.extend(l1[i:])
        elif j < len(l2):
            ans.extend(l2[j:])

        return ans
```
