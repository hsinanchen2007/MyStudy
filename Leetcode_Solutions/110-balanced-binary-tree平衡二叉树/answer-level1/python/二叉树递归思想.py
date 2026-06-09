[]()### 解题思路
使用递归的思想，建立递归函数，返回值为以节点为根的高度，递归统计左右子树的高度，并进行比较，比较若差的绝对值大于1
则将judge进行修改

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
        if root==None:
            return True
        self.judge = True
        def helper(node):
            if node==None:
                #self.judge=True
                return 0
            else:
                l = helper(node.left)
                r = helper(node.right)
                if abs(l-r)>1:
                    self.judge=False
                height=max(l,r)+1
                return height
        helper(root)
        return self.judge
                
            
```