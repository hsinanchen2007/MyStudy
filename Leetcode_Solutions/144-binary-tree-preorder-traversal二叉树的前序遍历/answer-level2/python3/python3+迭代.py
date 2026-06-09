### 解题思路
用一个栈来储存每个节点，先储存右节点，再储存左节点，依次从尾部弹出，并且把弹出节点的左右节点加入栈里
![2019-12-04 23-50-14屏幕截图.png](https://pic.leetcode-cn.com/d84537eca43aa814d92692fc0d2be8b04b4333c433e612bca6eafc5a3e919433-2019-12-04%2023-50-14%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return None
        res = []
        stack = [root]
        while stack:
            p = stack.pop()
            res.append(p.val)
            if p.right:
                stack.append(p.right)
            if p.left:
                stack.append(p.left)
        return res
```