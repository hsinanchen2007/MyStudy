通过两个动态规划方程解决

## 求回文串

- 设grid[i][j]为以i结尾，长度为j的字符串变成回文串需要的最小修改次数
- 初始化值：grid[i][1] = 0; grid[i][0] = 0
- 状态转移方程：
    当s[i] == s[i-j+1]时,grid[i][j]=grid[i-1][j-2]
    否则，grid[i][j]=grid[i-1][j-2]+1

## 求分割后的回文串组

- 设dp[i][j]为对以i结尾的子串分割j次得到的子串都是回文串需要的最小修改次数
- 初始值：dp[0][j] = 0
- 状态转移方程：
    dp[i][0] = grid[i][i+1]
    dp[i][j] = min(dp[i-L][j-1] + grid[i][L]); 1<=L<=i

## 代码实现

    func palindromePartition(s string, k int) int {
        if s=="" || k >= len(s) {
            return 0
        }
        n:=len(s)
        dp := make([][]int, n)
        grid := make([][]int,n)
        for i:=0;i<n;i++ {
            dp[i] = make([]int,k)
            grid[i] = make([]int,n+1)
        }

        for i:=1;i<n;i++{
            for j:=2;j<=i+1;j++{
                grid[i][j]=grid[i-1][j-2]
                if s[i]!=s[i-j+1] {
                    grid[i][j]++
                }
            }
        }

        for i:= 1;i<n;i++ {
            dp[i][0] = grid[i][i+1]
            for j:=1;j<k;j++ {
                dp[i][j] = dp[i-1][j-1]+grid[i][1]
                for l:=2;l<=i;l++{
                    dp[i][j] = min(dp[i][j],dp[i-l][j-1]+grid[i][l])
                }
            }
        }
        return dp[n-1][k-1]
    }

## 注意

动态规划循环的边界值一定要想清楚
这道题中l是可以等于i的，我再这一点卡了很久