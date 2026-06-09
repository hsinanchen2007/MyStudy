```
func maxJumps(arr []int, d int) int {
	var (
		i, j   int
		length = len(arr)
		dp     = make([]int, length)
		set    = make([]bool, length)
	)

	if length == 0 {
		return 0
	}

	for i = 0; i < length; i++ {
		maxJumpsI(arr, dp, set, i, d)
	}
	j = dp[0]
	for i = 1; i < length; i++ {
		if dp[i] > j {
			j = dp[i]
		}
	}
	return j
}

func maxJumpsI(arr, dp []int, set []bool, x, d int) int {
	if !set[x] {
		dp[x] = 1
	}
	set[x] = true
	for i := 0; i < d && x-1-i >= 0; i++ {
		if arr[x-1-i] < arr[x] {
			if !set[x-1-i] {
				maxJumpsI(arr, dp, set, x-1-i, d)
			}
			if dp[x-1-i]+1 > dp[x] {
				dp[x] = dp[x-1-i] + 1
			}
			continue
		}
		break
	}
	for i := 0; i < d && x+1+i < len(arr); i++ {
		if arr[x+1+i] < arr[x] {
			if !set[x+1+i] {
				maxJumpsI(arr, dp, set, x+1+i, d)
			}
			if dp[x+1+i]+1 > dp[x] {
				dp[x] = dp[x+1+i] + 1
			}
			continue
		}
		break
	}
	return dp[x]
}

```
