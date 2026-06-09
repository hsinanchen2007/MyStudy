**思路：**

![示意图](https://pic.leetcode-cn.com/702fa9c7bbdb5b3516b2c8fb55c8d6470ff923cc741acf678bcde4d3ed8d69f4.png)

如图所示，当一号玩家选择了一个红色的结点，可能会将二叉树切割为 3 个部分（连通分量），如果选择的是根结点，则可能是 2 个部分或 1 个部分，如果选择叶结点，则是 1 个部分。不过无论哪种情况都无关紧要，我们都可以当成 3 个部分来对待，例如一号玩家选择了一个叶结点，我们也可以把叶结点的左右两个空指针看成大小为 0 的两个部分。

下面我们就来思考，**二号玩家怎样选择蓝色结点才是最优呢**？答案是：选择离红色结点最近，且所属连通分量规模最大的那个点。也就是示例图中的 1 号结点。如果我们选择了 1 号结点为蓝色结点，那么可以染成红色的点就只剩下 6 号点和 7 号点了，而蓝色可以把根结点和其左子树全部占据。

如何确定蓝色是否有必胜策略，就可以转换为，被红色点切割的三个连通分量中，**是否存在一个连通分量，大小大于所有结点数目的一半**。统计三个连通分量大小的过程，可以用深度优先搜索（DFS）来实现。当遍历到某一结点，其结点值等于选定的红色结点时，我们统计这个结点的左子树 `red_left` 和右子树 `red_right` 的大小，那么我们就已经找到两个连通分量的大小了，最后一个父结点连通分量的大小，可以用结点总数减去这两个连通分量大小，再减去红色所占结点，即 `parent = n - red_left - red_right - 1`。


**代码：**
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        self.red_left, self.red_right = 0, 0
        
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            if root.val == x:
                self.red_left = left
                self.red_right = right
            return left + right + 1
        
        dfs(root)
        parent = n - self.red_left - self.red_right - 1
        judge = [parent, self.red_left, self.red_right]
        return any([j > n // 2 for j in judge])
```
