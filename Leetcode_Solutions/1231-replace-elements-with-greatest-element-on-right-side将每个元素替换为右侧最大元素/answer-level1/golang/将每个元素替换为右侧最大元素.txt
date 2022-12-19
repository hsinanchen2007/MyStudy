### 解题思路
依次遍历切片每个元素，并选举出右边最大值替换。

### 代码

```golang
func replaceElements(arr []int) []int {
	for i := 0; i < len(arr); i++ {
		max := -1
		for j := i + 1; j < len(arr); j++ {
			if arr[j] > max {
				max = arr[j]
			}
		}
		arr[i] = max
	}
	return arr
}
```