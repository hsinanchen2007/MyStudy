### 解题思路
该题的数据结构又升级为二叉树了。但是中心思想不变，每一层的结果由下面两层的结果得出，与问题I十分相似。这种由底向上的遍历方式，让我想到左右根的后序遍历方式，因此借助递归实现。在遍历过程中我们只需要保存最近的两代的中间结果即可（在解决思路中从保存最近两代的最优解转换成了保存第一代孩子节点的抢/不抢两种状态下的最优解，最终的最优解从抢/不抢root节点的两种状态中比较而得）。这种方式比起由底向上的遍历方式，不用保存所有的中间结果，因此时间复杂度虽然同为O(n)，但是时间更快，空间开销也更小。

### 代码
- 自顶向下
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    rob_dict = {}
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root in self.rob_dict:
            return self.rob_dict[root]
        if not root.left and not root.right:
            self.rob_dict[root] = root.val
            return root.val
        get = root.val
        # 抢，只能抢下下家
        if root.right:
            get += self.rob(root.right.left) + self.rob(root.right.right)
        if root.left:
            get += self.rob(root.left.left) + self.rob(root.left.right)
        # 不抢，抢下家
        res = max(get, self.rob(root.left) + self.rob(root.right))
        self.rob_dict[root] = res
        return res

```
- 自底向上
```python3
class Solution:

   def rob(self, root):
        nost, st = self.rob_help(root)
        return max(nost, st)

    def rob_help(self, root: TreeNode):
        if not root:
            return 0, 0
        if (not root.left) and (not root.right):
            return 0, root.val    # 不抢，抢
        lval, x = self.rob_help(root.left)
        rval, y = self.rob_help(root.right)
        return max(lval, x)+max(rval, y), lval + rval + root.val
```