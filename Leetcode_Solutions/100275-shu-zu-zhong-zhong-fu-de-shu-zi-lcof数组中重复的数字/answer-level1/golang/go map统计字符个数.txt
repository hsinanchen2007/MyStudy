### 解题思路
此处撰写解题思路
构造一个mao，来解决。如果map中有此key，则表示重复，如果没有此key，则表示没有此重复。


### 代码

```golang
func findRepeatNumber(nums []int) int {
	repMap := make(map[int]int)
	for _, i := range nums {
		res, ok := repMap[i]
		fmt.Println(res, ok, i)
		if ok {
			return res
		} else {
			repMap[i] = i
		}
	}
	return 0
}
```