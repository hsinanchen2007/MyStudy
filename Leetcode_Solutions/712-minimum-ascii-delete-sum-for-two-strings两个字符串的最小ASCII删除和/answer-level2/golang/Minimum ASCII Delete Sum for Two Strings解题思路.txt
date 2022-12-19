### 解题思路
此处撰写解题思路
![Minimum ASCII Delete Sum for Two Strings.jpg](https://pic.leetcode-cn.com/4e72eb2c8b6b4e83a895e9d959aea18b61efd2f5d32331954efda9533e12858d-Minimum%20ASCII%20Delete%20Sum%20for%20Two%20Strings.jpg)


### 代码

```golang
func minimumDeleteSum(s1 string, s2 string) int {
    n:=len(s1)
    m:=len(s2)

    dp := make([][]int,n+1)
    for i := 0; i < n+1; i++ {
        dp[i] = make([]int, m+1)
    }
    for i:=1;i<=n;i++{
        dp[i][0]=dp[i-1][0]+int(s1[i-1] )
    }
    for j:=1;j<=m;j++{
        dp[0][j]=dp[0][j-1]+int(s2[j-1])
    }
    for i:=1;i<=n;i++{
        for j:=1;j<=m;j++{
            if s1[i-1]==s2[j-1]{
                dp[i][j]=dp[i-1][j-1]
            }else{
                if dp[i-1][j]+int(s1[i-1])<dp[i][j-1]+int(s2[j-1]){
                    dp[i][j]=dp[i-1][j]+int(s1[i-1])
                }else{
                    dp[i][j]=dp[i][j-1]+int(s2[j-1])
                }
            }
        }
    }
    return dp[n][m]
}
```