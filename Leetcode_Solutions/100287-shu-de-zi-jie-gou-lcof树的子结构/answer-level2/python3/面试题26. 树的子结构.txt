![image.png](https://pic.leetcode-cn.com/308a4d57007e3a5205de951101766963159598096f83b0257060e0a15415e5ee-image.png)

### 解题思路
分为两步走：
1.明确思路，需要将所有的A中的节点，都与B中根节点相比较，如果遇到相等，则进入2
2.判断A,B的子节点，如果相同则继续判断左右节点。一旦遇到错误，回到1，否则返回True

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def subcheck(self, A, B):
        if not A:
            return False
        if A.val != B.val:
            return False
        if B.left:
            if not self.subcheck(A.left, B.left):
                return False
        if B.right:
            if not self.subcheck(A.right, B.right):
                return False
        return True

        
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        if A.val == B.val:
            if self.subcheck(A, B):
                return True
        if A.left:
            if self.isSubStructure(A.left, B):
                return True
        if A.right:
            if self.isSubStructure(A.right, B):
                return True
        return False
```