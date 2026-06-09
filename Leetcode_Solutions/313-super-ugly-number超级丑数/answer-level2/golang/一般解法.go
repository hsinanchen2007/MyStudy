``` go
const UINT_MAX = int(^uint(0) >> 1)

func nthSuperUglyNumber(n int, primes []int) int {
	pointers := make([]int, len(primes))
	dp := make([]int, n)
	dp[0] = 1

	for i := 1; i < n; i++ {
		currMin := UINT_MAX
		for j := 0; j < len(primes); j++ {
			if currMin > dp[pointers[j]]*primes[j] {
				currMin = dp[pointers[j]] * primes[j]
			}
		}
		for j := 0; j < len(primes); j++ {
			if dp[pointers[j]]*primes[j] == currMin {
				pointers[j]++
			}
		}
		dp[i] = currMin
	}
	return dp[len(dp)-1]
}
```
