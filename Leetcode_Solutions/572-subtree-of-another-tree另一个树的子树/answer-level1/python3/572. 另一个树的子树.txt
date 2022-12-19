### 解题思路
先遍历树s的每个结点，保存与t结点值相同的结点指针，然后对每个可能的指针，做同步比对，有一个完全相同，则返回True；否则False。时间复杂度为O(MN)，M为s树结点个数，N为t树结点个数，空间复杂度为O(M)。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def valid(root1,root2):
            if root1 and root2:
                left = valid(root1.left,root2.left)
                right = valid(root1.right,root2.right)
                if left and right and root1.val==root2.val:
                    return True
                else:
                    return False
            else:
                if not root1 and not root2:
                    return True
                else:
                    return False
        
        def preOrder(root):
            if root:
                if root.val==t.val:
                    tmp.append(root)
                preOrder(root.left)
                preOrder(root.right)
        
        tmp = []
        preOrder(s)
        # print(tmp)
        for val in tmp:
            if valid(val,t):
                return True
        return False

```