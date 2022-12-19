### 解题思路
sort方法排序，
输出前k个

### 内存消耗
执行用时 :40 ms, 在所有 Go 提交中击败了47.31%的用户
内存消耗 :6.3 MB, 在所有 Go 提交中击败了100.00%的用户

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
	if len(arr) < k {
		return arr
	}
	sort.Ints(arr)
	return arr[:k]
}

```