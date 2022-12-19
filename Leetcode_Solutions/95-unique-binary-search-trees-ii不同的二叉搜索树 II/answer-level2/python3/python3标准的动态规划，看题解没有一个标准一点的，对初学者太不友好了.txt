### 解题思路
标准的动态规划，最标准的，还没有优化，适合初学者的。
1.定义dp数组，dp[i][j]   存储数字为i---j之间的所有可能的情况,dp为三维数组
2.规定初始值，如果i==j,表示只有一个节点的情况，添加节点val为i即可，
i>j初始化为空列表，其他情况初始化为[None]，画一个矩阵就可以看出来了。
3.确定dp方程，求dp[i][j],以i-j之间数字为顶点的所有情况相加即可，
例如，求dp[1][3]，分别以1,2,3为顶点，以1为顶点，左边值更大，右边值更小,
左子树为dp[1][0]，右子树为dp[2][3]，两个树排列组合就可以,dp[1][0]为None,
4.确定循环顺序，画矩阵可以看出来，从下向上进行循环，求dp[1][3]必须要知道dp[2][3]，
求dp[2][4]必须要知道dp[3][4],dp[2][3]，
5.写代码时候注意边界情况需要额外判断
### 代码

```python3
class Solution:
    def generateTrees(self, n: int):
        if n == 0:
            return None
        # 对dp进行初始化
        dp = []
        for i in range(0, n+1):   # 初始化dp
            dp.append([])
            for j in range(0, n+1):
                if i == j:
                    dp[i].append([TreeNode(i)])
                elif i < j:
                    dp[i].append([])
                else:
                    dp[i].append([None])
        dp[0][0] = [None]
        for i in range(n-1, 0, -1):  # 自下向上进行循环
            for j in range(i+1, n+1):
                for r in range(i, j+1):   # i-j每一个节点为顶点的情况
                    left = r+1 if r < j else r    # 右边的值需要边界判断，不然会溢出数组
                    for x in dp[i][r-1]:          # 左右子树排列组合   
                        for y in dp[left][j]:
                            node = TreeNode(r)     
                            node.left = x
                            node.right = y
                            if r == j:
                                node.right = None
                            dp[i][j].append(node)      # dp[i][j]添加此次循环的值
        return dp[1][n]
```