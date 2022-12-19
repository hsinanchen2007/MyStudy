### 解题思路
定义一个map，使用切片元素作为key，出现次数作为value，遍历切片，当value大于len(nums) / 2 时return即可。

### 代码

```golang
func majorityElement(nums []int) int {
	t := len(nums) / 2
	
	m := make(map[int]int)
	for _, v := range nums {
		m[v] = m[v] + 1
		if m[v] > t {
			return v
		}
	}
	return -1
}
```