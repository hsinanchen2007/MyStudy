### 解题思路
这道题考量的是二叉树的遍历，根据题目要求，我们要从先序遍历、中序遍历、后序遍历中选出一种较为直观的遍历顺序来求得遍历过程中的最值。分析题目可得：最值的出现不一定包括根节点，意思是，最值可能出现在整棵树的一部分，可能是一条路走到黑（从某个节点直达叶子节点），也可能是由该节点和其左右两个孩子组成和。分析到这，可以看出，值应该*先计算左子树最值、在计算右子树最值，最后加上本节点的值构成*，这个顺序恰好是**后序遍历**的顺序。

有了后续遍历的想法，接下来就是实现比较大小的操作了，请看代码注释。

既然最值可能出现在某个“地方”，较为直观的想法就是设置一个全局最大值，然后在遍历的过程中，我们计算一个和然后和这个全局最大值进行比较。
ps：这道题如果再进一步，可以要求输出最大值组成的路径，我没有深入思考，但是我觉得可以再定义一个path列表，记录路径，通过最值来更新这个列表，如有不对，请赐教。

最后，我分享一个我做二叉树遍历题的小技巧，在思考递归时，我会将题目简化为最简单的形式，一个根节点和两个孩子节点，然后来解题，反正，递归会帮我们求得左右孩子节点的某项值，并不需要关注递归是如何递归的。


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
        self.ans = float("-inf")  # 全局最小值，初始化为负无穷。
        self.helper(root)

        return self.ans

    def helper(self, node):
        # 递归出口，访问到叶子的孩子节点时，退出递归
        if node is None:
            return 0

        # 后序遍历
        left = max(self.helper(node.left), 0)   # 获得当前遍历节点的左子树的最值
        right = max(self.helper(node.right), 0)  # 获得当前遍历节点的右子树的最值

        # 后序遍历执行操作的地方
        # --------------------------
        tem = left + right + node.val  # 题解中说的两种情况的综合，因为left和right可能为0，此时就是一条路走到黑，否则就是包含左右孩子。
        self.ans = max(tem, self.ans)  # 更新全局最小值
        # --------------------------

        return node.val + max(left, right)  # 递归函数（调用）的返回值，区别于递归出口，上文中left、right的值是从这返回的

            
```