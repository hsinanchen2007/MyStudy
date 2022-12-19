dfs 返回结果记录两个值 
第一个 当前节点所在的子树 目前还多多少个硬币(可为负)
第二个 当前节点所在的子树需要多少次移动 移动：left节点所在的子数总移动数目+right节点所在的子数总移动数目+abs(left节点多的硬币)+abs(right节点多的硬币)

```
class Solution(object):
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def count(node):
            if node is None:
                return 0,0
            val1,total1 = count(node.left)
            val2,total2 = count(node.right)
            val = val1+val2+node.val-1
            total= total1+total2+abs(val1)+abs(val2)
            return val,total
        return count(root)[1]
```
