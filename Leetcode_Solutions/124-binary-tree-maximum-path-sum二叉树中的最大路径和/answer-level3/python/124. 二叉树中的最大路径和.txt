### 解题思路
- 非局部变量声明nonlocal，这样可以全局使用，不需要使用数组保存最值；
- 返回左子树最大值，如果是负数则赋值为0，相加时不考虑左子树；
- 返回右子树最大值，如果是负数则赋值为0，相加时不考虑右子树；
- 更新maxsum为当前最大值，返回当前节点最优情形；
- 注意：
1. 必须要包含节结点，左右子树选择最大的，这样此时根节点作为原根节点的左子树或右子树才可与原节点相连；
2. maxsum储存了每一个节点作为根节点时的最值，超过该最值时才会更新；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def findmax(root):
            nonlocal maxsum
            if not root:
                return 0
            left = max(findmax(root.left), 0)
            right = max(findmax(root.right), 0)
            maxsum = max(left + right + root.val, maxsum)
            return root.val + max(left, right)
        maxsum = float('-inf')
        findmax(root)
        return maxsum
```