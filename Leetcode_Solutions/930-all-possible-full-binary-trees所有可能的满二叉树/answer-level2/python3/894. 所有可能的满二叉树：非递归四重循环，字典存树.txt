### 解题思路

`N`为偶数时无解，字典存树，本质四重循环，多节点的二叉树都是由少节点的二叉树组合而成，返回的二叉树数组实质在共用子树。

代码里`d[n]`为节点数是`n`的二叉树数组，`i`则该二叉树代表左侧分配的节点数，`n - i - 1`则为右侧分配的节点数，再遍历组合左右节点数对应的二叉树数组即可得到`n`个节点时的二叉树数组。

### 代码

```python []
class Solution:
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        if N % 2:
            d = collections.defaultdict(list)
            d[1].append(TreeNode(0))
            for n in range(3, N + 1, 2):
                for i in range(1, n, 2):
                    for leaves in itertools.product(d[i], d[n - i - 1]):
                        d[n].append(TreeNode(0))
                        d[n][-1].left, d[n][-1].right = leaves
            return d[N]
```

![image.png](https://pic.leetcode-cn.com/b760777afd058b3ee00ae67a793d1ce88bfc3a83e910f8e641a766625f310650-image.png)
