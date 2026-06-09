![1.jpg](https://pic.leetcode-cn.com/94e3f0ec7d4c2139e9a5149a709fecb93e435880dc76a1ae9ea4d2cd0f9468a7-1.jpg)
以下是题解
```go
func lengthOfLongestSubstring(s string) int {
length := 0
Tag:
	for slowIdx, fastIdx := 0, 0; fastIdx < len(s); fastIdx++ {
		for idxI, idxJ := slowIdx, fastIdx; idxI < idxJ; idxI++ {
			if s[idxI] == s[idxJ] {
				slowIdx++
				continue Tag
			}
			if idxI == idxJ-1 {
				idxJ--
				idxI = slowIdx - 1
			}
		}
		length = fastIdx - slowIdx + 1
	}
	return length
}
```
