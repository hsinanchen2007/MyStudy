![image.png](https://pic.leetcode-cn.com/e4c88eb28eb269b2175ad9c930fe4bdb50bb3e98ebdde8b699339dc59494c9c3-image.png)


```
'''
递归查找以每个子树的根为起点的最长交错路径，
每一层递归需要记录到达当前节点时候走的方向，
向上一层返回当前位置下一步走相反方向时候
能达到的最长路径长度
'''

class Solution:

    def dfs(self, root, direc, ans) -> int:
        if root is None:
            return 0

        l_len = self.dfs(root.left, 'left', ans)
        r_len = self.dfs(root.right, 'right', ans)
        ans[0] = max(max(l_len, r_len) + 1, ans[0])

        return l_len+1 if direc == 'right' else r_len+1

    def longestZigZag(self, root: TreeNode) -> int:
        ans = [0]
        self.dfs(root, 'left', ans)
        return ans[0] - 1
```
