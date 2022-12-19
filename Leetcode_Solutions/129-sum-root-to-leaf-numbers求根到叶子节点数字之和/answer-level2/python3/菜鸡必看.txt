### 解题思路
思路就是到叶子节点就往res数组加内容 然后sum
但是在递归的时候有点小乱
看注释奥铁汁萌

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        res=[]
        def helper(root,x) :
            if not root :
                return
            # 这一步必须有 不然他娘的疯狂报错
            if not root.left and not root.right :
                res.append(root.val+10*x)
                return
            # 之前写的时候 直接把append写在上面not root地方 但其实这样就每到一个空节点就往数组加上面的和 并不是到题目要求的叶子节点
            cur=root.val+10*x
            helper(root.left,cur)
            helper(root.right,cur)
        helper(root,0)
        return sum(res)
```