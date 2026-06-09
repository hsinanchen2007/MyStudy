### 解题思路
创建一个 map 来存储数组中元素及其个数，当某个元素在 map 中再次出现时，返回该元素

### 代码

```golang
func findRepeatNumber(nums []int) int {
	var cases = make(map[int]int)
	var r int
	for i := 0; i < len(nums); i++ {
		if _, ok := cases[nums[i]]; ok {
			r = nums[i]
			break
		}else {
			cases[nums[i]] = 1
		}
	}
	return r

}
```