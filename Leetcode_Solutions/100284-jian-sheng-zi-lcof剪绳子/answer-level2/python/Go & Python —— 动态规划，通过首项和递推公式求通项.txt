### Go
![c3040448887128c92f2043519adb437.png](https://pic.leetcode-cn.com/117f01667cf31a019af6a5340e533d55f4dd96e657a006af634f3f1065242507-c3040448887128c92f2043519adb437.png)
### Python
![cb9981ef330ea770effef1c7976eebd.png](https://pic.leetcode-cn.com/c6526fee91fa9349ae00b0fe3d942f5434961366963c7005a1f293f9461d7fc1-cb9981ef330ea770effef1c7976eebd.png)
### 动态规划理解
1. 动态规划就是数学归纳法
2. 像高中数列题，已知`首项`和`递推公式`去求`第n项`
3. 本题的`首项`是：n=1的时候，答案为1
4. 本题的`递推关系`是：对于n=k(k>=2)时，需要考虑怎么剪第一刀，可以是`1+(k-1)`、`2+(k-2)`、……、`(k-1)+1`，在这些情况里取最大值
### 代码
```go []
func cuttingRope(n int) int {
	dp := make(map[int]int)
	dp[1] = 1 // 首项
	for i := 2; i < n+1; i++ {
		j, k := 1, i-1
		res := 0
		for j <= k {
			res = max(res, max(j, dp[j])*max(k, dp[k])) // 递推公式
			j++
			k--
		}
		dp[i] = res
	}
	return dp[n]
}

func max(i int, j int) int {
	if i > j {
		return i
	}
	return j
}

```
```python []
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = {1: 1} # 首项
        for i in range(2, n+1):
            dp[i] = max(max(j, dp[j])*max(i-j, dp[i-j]) for j in range(1, i) if j <= i-j) # 递推公式
        return dp[n]

```
