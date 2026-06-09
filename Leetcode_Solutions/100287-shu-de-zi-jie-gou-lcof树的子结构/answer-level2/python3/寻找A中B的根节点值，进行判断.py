### 解题思路
先在A中遍历找到B的根节点的值，接着判断该子树是否与B相同
因为A中可能存在多个B根节点的值，所以需要完整遍历A

![下载 (6).png](https://pic.leetcode-cn.com/7bd7e96e90465c6f75f97cfaf49aa85d0accca55d0b8f231c91cef430cb8864a-%E4%B8%8B%E8%BD%BD%20\(6\).png)

### 代码

```

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not (A or B):
            return True
        if not (A and B):
            return False
        B.single = False
        b_target = B.val
        def find(b_target, A):
            if not A:
                return True
            if A.val == b_target:
                B.single = check(A,B)
            return find(b_target, A.left) and find(b_target, A.right)
        find(b_target, A)
        return B.single


def check(A,B):
    if not (A or B):
        return True
    if not B:
        return True
    if not A:
        return False
    if B.val != A.val:
        return False
    return check(A.left,B.left) and check(A.right,B.right)
```

