### 解题思路
- dp[i] = 相连字母 ? dp[i-1] + 1 : 1
- map_abc[字母x] = max(dp[i], max_abc[字母x])

### 代码

```golang
func findSubstringInWraproundString(p string) int {
    return method_dp(p)
}

//map_abc  key = 字母x, value = 以字母x结束的个数。 如map_abc[c]=4表示 c, bc, abc, zabc
//dp[0] = 1
//dp[i] = 是相连字母 ? dp[i-1] + 1 : 1
//map_abc[p[i]] = max(dp[i], max_abc[p[i]])
//return sum(map_abc)
func method_dp(p string) int {
    if len(p) < 2 {
        return len(p)
    }

	map_abc := make([]int, 123)
	dp := make([]int, len(p))
    dp[0] = 1
    map_abc[p[0]] = 1

    for i := 1; i < len(p); i++ {
        dp[i] = 1
		if p[i] - p[i-1] == 1 || int(p[i]) - int(p[i-1]) == -25 {
			dp[i] += dp[i-1]
		}
		map_abc[p[i]] = getMax(dp[i], map_abc[p[i]])
    }

    cnt := 0
	for _, n := range map_abc {
		cnt += n
	}
	return cnt
}

func getMax(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```