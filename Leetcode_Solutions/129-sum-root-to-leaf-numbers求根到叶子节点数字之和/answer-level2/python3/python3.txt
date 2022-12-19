### 解题思路
遍历出所有的路径，在求和即可
![UC截图20191205143727.png](https://pic.leetcode-cn.com/e7a5371b5fee3d669b53ab83aa68d13ea5bd93baf5da871ddf88f59e05163c17-UC%E6%88%AA%E5%9B%BE20191205143727.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        res = []
        if not root: return 0
        def helper(root,tmp):
            if not root:
                return
            if not root.left and not root.right:
                tmp += str(root.val)
                res.append(tmp)
                return
            helper(root.left,  tmp + str(root.val))
            helper(root.right, tmp + str(root.val))
        helper(root,'')
        ans = 0
        for item in res:
            ans += int(item)
        return ans
```