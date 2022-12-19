### 解题思路
官方解golang实现

### 代码

```golang
func minDistance(word1 string, word2 string) int {
    n,m := len(word1),len(word2)
    //任意一个为空
    if n * m == 0{
        return n+m
    }
    //初始化dp 二维数组 (n+1) x (m+1)
	dp := make([][]int,n+1)
    //初始化word1
    for i:=0;i<=n;i++{
        dp[i] = make([]int,m+1)
        dp[i][0] = i
    }
    //初始化word2
    for j:=1;j<=m;j++{
        dp[0][j] = j
    }
    //注意边界问题
    for i:=1;i<=n;i++{
        for j:=1;j<=m;j++{
            if word1[i-1] == word2[j-1]{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]-1) +1    
            }else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) +1    
            }
        }
    }
    return dp[n][m]
}

func min(a, b, c int) int {
	if a > b {
		a = b
	}
	if a > c {
		a = c
	}
	return a
}
```