### 解题思路
先层序遍历，再反转奇数索引的层
![UC截图20191205102407.png](https://pic.leetcode-cn.com/aa292909f9131036a440c377004a384a81936e11bca3f11e0613a59b3e9959d9-UC%E6%88%AA%E5%9B%BE20191205102407.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        def helper(root, depth):
            if not root: return 
            if len(res) == depth:
                res.append([])
            res[depth].append(root.val)
            helper(root.left, depth + 1)
            helper(root.right, depth + 1)
        helper(root,0)
        for i in range(1,len(res),2):
            res[i] = res[i][::-1]
        return res
```