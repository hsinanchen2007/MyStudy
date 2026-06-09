### 解题思路
本质上还是二叉树的层次遍历
关键在于对奇、偶层做一个处理，奇数则正序即可，偶数则需要倒序
这里用到python的倒序处理：a[::-1]即为a数组的倒序

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode):

        if not root:return []

        queue = [root]
        level = 0
        result = []

        while queue:

            res = []

            for i in range(len(queue)):

                cur = queue.pop(0)
                res.append(cur.val)

                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)

            level += 1

            if level%2 != 0:
                result.append(res)
            else:
                result.append(res[::-1])

        return result
```