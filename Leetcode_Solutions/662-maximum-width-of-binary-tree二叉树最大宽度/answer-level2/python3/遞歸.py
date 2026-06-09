### 解题思路
思路有点类似head的parent节点是i,则left的index为2*i
                                  right的index为2*i+1
无非就是遞歸地進行
要麼是當前寬度-首次出現的節點+1
就是下一層的寬度
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        memo = {}
        def h(r,w,d):
            if not r:
                return 0
            if d not in memo:
                memo[d] = w
            return max(w-memo[d]+1,\
                    h(r.left,2*w,d+1),\
                    h(r.right,2*w+1,d+1))
        return h(root,0,0)
        
```