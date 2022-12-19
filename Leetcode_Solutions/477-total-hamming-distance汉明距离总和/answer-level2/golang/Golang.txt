纵向比较，32位对每一位来说，两两比较后的汉明距离是 (1 的个数) * (0 的个数)

0100 4
1110 14
0010 2

```go
func totalHammingDistance(nums []int) int {
	ans, numsLen := 0, len(nums)
	for i := 0; i < 32; i++ {
		haveOne := 0
		for _, num := range nums {
			haveOne += (num >> i) & 1  // 判断此位是否为 1
		}
		ans += haveOne * (numsLen - haveOne)
	}
	return ans
}
```