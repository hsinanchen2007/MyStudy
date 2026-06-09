### 解题思路

感谢[花花酱的视频解说](https://zxi.mytechroad.com/blog/searching/leetcode-842-split-array-into-fibonacci-sequence/)

这道题要注意，如果是Golang，提交的时候注意MaxInt应该是MaxInt32，
直接使用MaxInt有些测试案例不会通过。



### 代码

```golang

func splitIntoFibonacci(S string) []int {
	s := []rune(S) // Covert string into unicode slice.
	ans := []int{} // A slice to store the compute results.
	dfs(s, 0, &ans)
	return ans
}

// dfs is to search if there is a solution
// from the pos position.
func dfs(s []rune, pos int, ans *[]int) bool {
	// The whole string was processed,
	// then we return if len(ans) >= 3 to satisfy
	// the fibonacci definition.
	if pos == len(s) {
		return len(*ans) >= 3
	}
	// Determine the max length of substring
	// we need to compute.
	// If the current charater is 0, then we only need to
	// compute the next one, else we need to compute the next
	// 10 digits. 10**10 is bigger than the maximum can be stored
	// as int.
	maxLen := 1
	if s[pos] != '0' {
		maxLen = 10
	}
	// num represents the current number
	num := 0

	const MaxUint32 = ^uint32(0) 
	const MaxInt32 = int32(MaxUint32 >> 1) 

	for i := pos; i < min(pos+maxLen, len(s)); i++ {
		num = num*10 + int(s[i]-'0')

		if num > int(MaxInt32) {
			break
		}

		if len(*ans) >= 2 {
			sum := (*ans)[len(*ans)-1] + (*ans)[len(*ans)-2]
			if num > sum {
				break
			} else if num < sum {
				continue
			}
		}
		*ans = append(*ans, num)
		if dfs(s, i+1, ans) {
			return true
		}
		// Popout the current position.
		*ans = (*ans)[:len(*ans)-1]
	}
	return false
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

```