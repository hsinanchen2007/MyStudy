### 解题思路
对于树状结构，通过递归来遍历每个节点，判断对应位置是否相同

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        try:
            if p.val == q.val:
                if p.left == None and p.right == None and q.left == None and q.right == None:
                    return True
                else:
                    return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
            else:
                return False
        except:
            return False
```