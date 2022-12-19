### 解题思路
dfs
![UC截图20200104141933.png](https://pic.leetcode-cn.com/546612127813bf1cb1e1bf9a14f2575ad7b0f81a7f15ac0a20c67f23544876fc-UC%E6%88%AA%E5%9B%BE20200104141933.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def __init__(self):
        self.maxvalue = 0

    def maxAncestorDiff(self, root: TreeNode) -> int:
        def help(root,minval,maxval):
            if not root:
                return
            self.maxvalue = max(self.maxvalue,abs(root.val - minval),abs(root.val - maxval))
            minval = min(root.val, minval)
            maxval = max(root.val, maxval)
            help(root.left,minval,maxval)
            help(root.right,minval,maxval)
        help(root,root.val, root.val)
        return self.maxvalue
```