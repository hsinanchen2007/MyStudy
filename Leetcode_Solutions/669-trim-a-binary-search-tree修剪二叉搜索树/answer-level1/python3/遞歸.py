### 解题思路
所謂的修剪tree其實只要思考當前節點的狀況即可:

1.當前爲None-> None

2.當前>R 當前及right樹都要剪掉,則遞歸的執行只要剪對應的left樹即可
      <L 遞歸地執行right樹
3.
反正left和right都需要剪

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        def t(n):
            if not n:
                return
            elif n.val > R:
                return t(n.left)
            elif n.val < L:
                return t(n.right)
            else:
                n.left = t(n.left)
                n.right = t(n.right)
                return n
        return t(root)
        
```