### 解题思路
参考这个答案的 golang 版本：https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/java-gou-zao-10cha-shu-ju-ti-kan-zhu-shi-ba-by-wuy/

### 代码

```golang
func findKthNumber(n int, k int) int {
	currentNode := 1
	k--

	for k > 0 {
		firstNode := currentNode
		lastNode := currentNode + 1
		childrenCount := 0

		for firstNode <= n {
			childrenCount += int(math.Min(float64(lastNode), float64(n+1))) - firstNode
			firstNode *= 10
			lastNode *= 10
		}

		if childrenCount > k {
			currentNode *= 10
			k--
		} else {
			k -= childrenCount
			currentNode++
		}
	}
	return currentNode
}
```