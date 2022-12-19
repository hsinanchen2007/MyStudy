### 解题思路
judge函数思路：
1.若根结点为空，则平衡，高度为0；
2.若非空，则判断其左子树是否平衡，若不平衡，返回False,高度可取任意值，此处取-1；
3.右子树同理；
4.若左右子树都平衡，则判断相对于根结点而言，左右子树是否平衡，判断中用到了左右子树高度，所以要保留高度信息；
！最后调用judge函数，提取函数是否平衡的信息；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.judge(root)[0]
    def judge(self, root):
        if not root:
            return True, 0
        lbalance, lheight = self.judge(root.left)
        if not lbalance:
            return False, -1
        rbalance, rheight = self.judge(root.right)
        if not rbalance:
            return False, -1
        return abs(lheight - rheight) < 2, 1 + max(lheight, rheight)
```