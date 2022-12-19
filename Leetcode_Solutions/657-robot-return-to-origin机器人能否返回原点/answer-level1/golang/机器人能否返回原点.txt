### 解题思路
机器人回到原点，必须满足向左的数量等于向右的数量并且向上的数量等于向下的数量。

### 代码

```golang
func judgeCircle(moves string) bool {
	md := make(map[rune]int)
	for _, v := range moves {
		md[v]++
	}
	if md['L'] == md['R'] && md['U'] == md['D'] {
		return true
	}
	return false
}
```