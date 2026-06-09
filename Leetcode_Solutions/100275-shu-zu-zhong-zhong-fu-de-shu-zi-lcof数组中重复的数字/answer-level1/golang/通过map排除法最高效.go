### 解题思路:
> 将已经存入的字符标记为1，如果map成功取出值说明有重复元素

``` go
func findRepeatNumber(nums []int) int {
	maps := make(map[int]int)
	var number int
	for _, v := range nums {
		if _,ok := maps[v]; ok {
			number = v
			break
		} else {
			maps[v] = 1
		}
	}
	return number
}
```