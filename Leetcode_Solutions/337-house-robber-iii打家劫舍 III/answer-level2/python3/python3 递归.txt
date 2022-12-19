### 解题思路
将一个节点的收益分成两部分，分别为偷取该节点的最大收益和不偷取该节点的最大收益
那么一个节点如果偷取它，它的偷取收益为 node.val + not_steal_left + not_steal_right，即它的左右子节点取不偷取的收益
如果该节点不偷取,它的左右子节点可以随意选择偷或不偷，那么最大收益为max(steal_left,not_steal_left) + max(steal_right,not_steal_right)
递归完成后，对root得到steal和not_steal的收益，取最大值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        #思路：递归
        def dp(node):
            #返回值是偷取该节点和不偷取该节点的最大收益
            if node == None:
                return (0,0)
            steal_left,not_steal_left = dp(node.left)
            steal_right,not_steal_right = dp(node.right)
            steal = not_steal_left + not_steal_right + node.val
            not_steal = max(steal_left,not_steal_left) + max(steal_right,not_steal_right)
            return (steal,not_steal)
        steal,not_steal = dp(root)
        return max(steal,not_steal)

```