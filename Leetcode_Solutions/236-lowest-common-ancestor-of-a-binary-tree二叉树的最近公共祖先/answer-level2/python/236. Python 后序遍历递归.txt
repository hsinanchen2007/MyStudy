### 解题思路
本方法基于后续遍历，递归函数的返回值是**子树所包括的待搜索节点的数量**，方法很简单，看代码即可。
trick: 在代码中已注释出，当已经在左子树找到答案时，不需要再遍历右子树。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        res = None
        def get_res(root, p, q):
            nonlocal res
            if root is None:
                return 0
            x = get_res(root.left, p, q)
            y = get_res(root.right, p, q) if x != 2 else 0 # 剪枝
            flag = x + y
            if root == p or root == q:
                flag += 1
            if flag == 2 and res is None:
                res = root
            return flag
        get_res(root, p, q)
        return res
```