### 解题思路
1. 两个节点的值都大于根节点，往右子树找
2. 两个节点的值都小于根节点，往左子树找
3. 两个节点把根节点卡在中间（可以等于），则找到了

### 代码

```python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):

        _smaller = p if p.val < q.val else q
        _bigger = q if p.val < q.val else p
        if root.val == p.val and root.val == q.val:
            return root.val
        else:
            if _smaller.val <= root.val <= _bigger.val:
                return root
            elif root.val > _bigger.val:
                return self.lowestCommonAncestor(root.left,_smaller,_bigger)
            else:
                return self.lowestCommonAncestor(root.right, _bigger, _smaller)



```