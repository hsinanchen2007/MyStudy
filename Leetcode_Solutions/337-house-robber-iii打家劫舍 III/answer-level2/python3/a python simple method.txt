### 解题思路

the first is choose other node
the second is choose current node

when judge next node, the value choose other node can be: 

if current node is chosen:
second = current value + left child choose other node + 
right child choose other node
first = left child choose bigger node + right child choose bigger node
return first, second

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:**粗体**
    def rob(self, root: TreeNode) -> int:
        one, two = self.rob2(root)
        return max(one, two)

    def rob2(self, root):
        if not root:
            return 0,0
        l1, l2 = self.rob2(root.left)
        r1, r2 = self.rob2(root.right)
        return max(l1, l2) + max(r1, r2), l1 + r1 + root.val
```