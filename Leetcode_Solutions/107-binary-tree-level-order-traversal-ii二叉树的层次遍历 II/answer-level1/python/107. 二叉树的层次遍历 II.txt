### 解题思路
BFS 层次遍历，后倒序

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        if not root:return []
        ans = []
        temp = []
        stack = [(1,root)]
        l = 1
        while stack:
            layer,r = stack.pop(0)
            if not r:continue
            else:
                if layer == l:
                    temp.append(r.val)
                else:
                    ans.append(temp)
                    temp = []
                    temp.append(r.val)
                    l += 1
                stack.append((layer + 1,r.left))
                stack.append((layer + 1,r.right))
        ans.append(temp)
        return ans[::-1]
```