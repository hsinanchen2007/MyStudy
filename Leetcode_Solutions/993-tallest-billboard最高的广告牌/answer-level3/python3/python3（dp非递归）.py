首先把两条互相比较的长度，变为一条，即把钢筋放左边的支架里，记为正；放右边记为负

然后就是转化为***背包问题***，背包问题是两种选择，拿与不拿。我们这题是三种选择，放左边，不拿，放右边

背包问题dp数组的一个维度是物品列表，另一个维度是背包容量，值代表物品价值总和
我们这dp数组的一个维度是钢筋列表rods，另一个维度是正负之和，即左右钢筋长度之差，值代表正向值和，即左边的钢筋长度

由于题中是求最大的安装长度，所以我们需要保证在分配第i个钢筋，正负之和一定时，正向值最大，即dp[i][j]最大，所以每次更新，都做了比较处理
可以优化成一维，但懒得改了。。

```
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        N = 2*sum(rods)+1
        M = len(rods)
        mid = int((N-1)/2)
        if M<2:
            return 0

        #dp[i][j]是rods里第i个数做选择时，正负和为j-mid时的正向值和
        dp = [[float('-inf')]*N for _ in range(M)]

        #dp数组初始化
        dp[0][mid+rods[0]] = rods[0]
        dp[0][mid] = 0
        dp[0][mid-rods[0]] = 0

        #遍历所有情况
        for i in range(M-1):
            for j in range(N):
                if dp[i][j] != float('-inf'):
                    tmp = rods[i+1]
                    # 正向
                    dp[i+1][j+tmp] = max(dp[i+1][j+tmp], dp[i][j] + tmp)
                    # 舍弃
                    dp[i+1][j] = max(dp[i+1][j], dp[i][j])
                    # 负向
                    dp[i+1][j-tmp] = max(dp[i+1][j-tmp], dp[i][j])
        ans = 0
        for i in dp:
            ans = max(ans, i[mid])
        return ans
```


