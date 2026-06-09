比赛的时候看题看得绕的，样例也有误导，其实按照样例里的条件，蓝色应该染在根节点看起来才能染到最多的点。

本质就是求左子树结点数，右子树结点数，自身子树以外的节点，这三个值里，是否能有一个值大于另外两个值之和，如果可以，蓝色选择这片区域作为起点去染色就能获胜。

具体方法就是左右根后序遍历一次树，复杂度$O(n)$，而且讲实话条件多余了，n完全没必要给出来，遍历一遍树n就出来了。

![image.png](https://pic.leetcode-cn.com/a96de30d966e3b97c320443812879932460065c9b6c06893a13dcf9ac4a86b15-image.png)

```python [group1]
class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        xl, xr = 0, 0                   #左右子树节点数
        def f(r):                       #后序遍历树，先求左右子树的节点数，最后得到根的节点数
            if not r:
                return 0
            left = f(r.left)
            right = f(r.right)
            if r.val == x:              #如果扫描到目标节点，就记录其左右子树节点数量
                nonlocal xl, xr
                xl = left
                xr = right
            return left + right + 1
        xp = f(root) - (xl + xr + 1)    #自身以外的节点数，计算根节点的节点数的同时，遍历了整棵树
        return (xp > xl + xr) or (xl > xp + xr) or (xr > xp + xl)
```
