执行用时 :
0 ms, 在所有Go提交中击败了100.00%的用户
内存消耗 :
2.7 MB, 在所有Go提交中击败了74.62%的用户
```
func lengthOfLongestSubstring(s string) int {
    val := []byte(s)
	kvMap := make([]int, 128)
	lens := len(s)
	var max, num int
	for i, j := 0, 0; i < lens && j < lens; j++ {
		if kvMap[val[j]] > i {
			i = kvMap[val[j]]
		}
		num = j - i + 1
		if num > max {
			max = num
		}
		kvMap[val[j]] = j + 1
	}
	return max
}
```