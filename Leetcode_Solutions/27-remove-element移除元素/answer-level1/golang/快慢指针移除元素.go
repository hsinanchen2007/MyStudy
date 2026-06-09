### 解题思路
使用快慢真慢指针f, s, 对数组元素进行循环，f指针每次循环自增，s只在当次循环的元素值不为题意给定的val时才自增
### 代码

```golang
func removeElement(nums []int, val int) int {
    l, s := len(nums), 0
	for f := 0; f < l; f++ {
		if nums[f] == val {
			continue
		}

		nums[s] = nums[f]
		s++
	}

	return s
}
```