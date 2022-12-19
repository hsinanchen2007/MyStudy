### 解题思路
- 若根节点为None，返回空列表；
- **helper函数思路：**
- sum值减去根节点值，若该路径满足题意，则当遇到叶子节点时，sum恰好为0；
- 判断根节点是否是叶子节点且此时是否满足题意，若满足题意，将临时结果加入解集；
- 若左子树非空，向左子树走一步，求解；
- 若右子树非空，向右子树走一步，求解

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        if not root:
            return res
        def helper(root, sum, tmp):
            sum -= root.val
            if not root.left and not root.right:
                if sum == 0:
                    res.append(tmp + [root.val])
            if root.left:
                helper(root.left, sum, tmp + [root.val])
            if root.right:
                helper(root.right, sum, tmp + [root.val])
        helper(root, sum, [])
        return res

```