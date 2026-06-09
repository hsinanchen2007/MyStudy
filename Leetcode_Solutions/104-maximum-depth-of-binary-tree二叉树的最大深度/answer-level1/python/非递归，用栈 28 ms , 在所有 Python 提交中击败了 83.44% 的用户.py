### 解题思路
不太理解递归，用hash表记录每次最大深度
用栈弹出的方式返回到没有遍历的节点

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        if not root: return 0
        cur=root
        stack = [cur]
        count={}
        pre = cur
        count[pre] = 1
        cur=cur.left
        while stack or cur:
            while cur:
                count[cur] = count[pre] + 1
                stack.append(cur)
                pre = cur
                cur=cur.left
            top=stack.pop()
            cur=top.right
            pre=top
        return max(count.values())

```