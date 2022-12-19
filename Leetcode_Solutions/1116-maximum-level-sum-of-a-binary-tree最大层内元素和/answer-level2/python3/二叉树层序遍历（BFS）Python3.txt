**思路：**

用队列进行层序遍历（宽度优先搜索）。把每层结点值相加求和，并更新答案。

**图解：**

![图解](https://pic.leetcode-cn.com/1ad8c8cf259a8d37fa997fafdb66f758390dffd296d1128cb459fff4b04e783e.gif)


**代码：**
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        ans = 1
        step = 1
        maxval = root.val
        q = [root]
        while q:
            t = []
            v = []
            for n in q:
                if n.left:
                    t.append(n.left)
                    v.append(n.left.val)
                if n.right:
                    t.append(n.right)
                    v.append(n.right.val)
            s = sum(v)
            step += 1
            if s > maxval:
                maxval = s
                ans = step
            q = t
        return ans
```
