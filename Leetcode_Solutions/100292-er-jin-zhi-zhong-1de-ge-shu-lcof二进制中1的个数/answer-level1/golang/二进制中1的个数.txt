### 解题思路
先将数字转化为字符串，再计算‘1’的数量。

### 代码

```golang
func hammingWeight(num uint32) int {
	count := 0
	s := fmt.Sprintf("%b", num)
	for _, v := range s {
		if v == '1' {
			count++
		}
	}
	return count
}
```