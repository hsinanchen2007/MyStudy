动态规划
使用map，是因为可能i值为负数，所以不能直接用数组；
思路：
mmap[i] = 1 表示i是定差子序列的第一个元素，之前的值都不在子序列中
mmap[i] = mmap[i-difference] + 1 表示i-difference值也在子序列中
两种情况可统一为mmap[i] = mmap[i-difference] + 1, mmap的默认值为0.

```
func longestSubsequence(arr []int, difference int) int {
	mmap := make(map[int]int) // mmap[i] = j 表示以i结尾的等差序列长度为j
	var res = 0
	for i := 0; i < len(arr); i++ {
		mmap[arr[i]] = mmap[arr[i]-difference] + 1
		if mmap[arr[i]] > res {
			res = mmap[arr[i]]
		}
	}
	return res
}
```