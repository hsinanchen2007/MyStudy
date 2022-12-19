### 解题思路
此处撰写解题思路

### 代码

```golang
func hammingDistance(x int, y int) int {
	m := x ^ y // 异或计算不同的位置
	count := 0
	for m > 0 { // 统计1的个数
		if m&1 > 0 { //每次拿出最后一位来跟1做 与操作，看是否为1 为1则 count++
			count++
		}
		m >>= 1//把比较过的那一位丢掉
	}
	return count
}
```