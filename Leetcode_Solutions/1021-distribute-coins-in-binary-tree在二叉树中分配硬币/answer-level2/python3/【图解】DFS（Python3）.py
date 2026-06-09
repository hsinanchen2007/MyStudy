# 【图解】DFS（Python3）


## 思路
我们定义函数`DFS(node)`，其功能在于计算以node为顶点的子树的需要多少硬币才平衡，正数表示我有多余，负数表示我需要别人给我硬币。 

我们知道一颗子树要想平衡，那么其节点的node.val之和应该等于节点的总数，因此`以node为顶点的子树的需要多少硬币才平衡`就等价于`node.val + l + r - 1`,其中l是 `dfs(node.left)`, r是` dfs(node.right)
`。 而我们的目标是求解移动多少步，才能使得树的金币平衡。

如下图： 实际上，我们需要移动的步骤就是`abs(3) + abs(-1) + abs(2) + abs(-1) + abs(2) + abs(0)`也就是 8步。

其正确性也容易证明，比如子节点的4，那么其一定有3个需要运出去的，并且我们只能运到父节点，然后父节点再看要不要继续转运。节点为0表示我们需要有一个从父节点转运过来，如果父节点不够它再管父节点或者另一个子节点要。因此我们只需要计算一共管别人要了多少次就行了，这恰好就是图中连线上的数字之和。

![image](https://pic.leetcode-cn.com/c1fada79dc97b14cc620922cb45fa64b0eb95cf83545e6cf5840d52cc4d2cc03.png)
（图来自： https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal）


## 代码
```python
class Solution:

    def distributeCoins(self, root: TreeNode) -> int:
        self.cnt = 0

        def dfs(node):
            if not node:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            self.cnt += abs(l) + abs(r)

            return node.val + l + r - 1
        dfs(root)
        return self.cnt

```


**复杂度分析**
- 时间复杂度：$O(N)$，其中N为节点的个数
- 空间复杂度：$O(H)$，其中H为树的深度

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)