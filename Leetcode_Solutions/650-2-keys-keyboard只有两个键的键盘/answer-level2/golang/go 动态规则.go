### 解题思路
dp[i] = dp[j] + i / j
i表示当前的数，j表示从i到1中能除的最大的数， 
原因：能整除说明只要把j复制再粘贴i/j次即可以变成i
如:
1个A = A = 0
2个A = A  + A = dp[1] + 2/1
3个A = A + A + A = dp[1] + 3/1
6个A = AAA  + AAA = dp[3] + 6 / 2
9个A = AAA  + AAA + AAA = dp[3] + 9/3



优化：i能整除j，则j至少要<=i/2， 所以j改为遍历=i/2至1， 这样可以减少遍历次数

### 代码

```golang
func minSteps(n int) int {
    return method_dp(n)
}

/*



dp[1] = 0
[2,n]... i++
	[i/2,1]... j--
		if i % j == 0 {
			dp[i] = dp[j] + i / j
			break
		}
*/
func method_dp(n int) int {
    dp := make([]int, n + 1)
    dp[1] = 0
    for i := 2; i <= n; i++ {
        for j := i / 2; j >= 1; j-- {
            if i % j == 0 {
                // fmt.Println(i,j)
                dp[i] = dp[j] + i / j
                break
            }
        }
    }
    // fmt.Println(dp)
    return dp[n]
}
```