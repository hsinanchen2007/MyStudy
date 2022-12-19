### 性能
Runtime: 0ms, 100%
Ram: 2.1MB, 65%


### 解题思路

感谢[❤❤❤花花酱的视频解说💖💖💖](http://zxi.mytechroad.com/blog/string/leetcode-763-partition-labels/)

*   我们用一个数组`lastIndex`记录每一个字符最后出现的位置。
*   从左边开始，先找出当前`i`位置字母最后出现的位置。
    *   如果此时就是该字母最后位置，说明我们找到一个分段。将下一段的起始设为当前截至+1。



### 代码

```golang
func partitionLabels(S string) []int {
	// Use a 26 length slice to
	// store all leters' frequency.
	lastIndex := make([]int, 26)
	for i, c := range S {
		lastIndex[int(c - 'a')] = i
	}
	ans := make([]int, 0)
	start := 0
	end := 0
	for i := 0; i < len(S); i++ {
		end = max(lastIndex[int(S[i] - 'a')], end)
		if i == end {
			ans = append(ans, end-start+1)
			start = end + 1
		}
	}

	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```