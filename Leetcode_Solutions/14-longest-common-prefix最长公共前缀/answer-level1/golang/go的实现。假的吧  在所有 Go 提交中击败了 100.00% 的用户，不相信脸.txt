### 解题思路
将所有的字符串拼接成一条字符串，记住每条字符串的开始位置， 然后统一将所有下标右移动

### 边界条件
- 第i个字符开始的位置 移动到了第i+1个字符的位置
- 第i个字符下标move 不等于 第i+1个字符下标move
- 是否有空串


### 代码

```golang
func longestCommonPrefix(strs []string) string {
// 先找出所有的初始下标
	var indexArr []int
	indexArr = append(indexArr, 0)
	lenAdd := 0
	for i := 0; i < len(strs) - 1; i++ {
		// 判断空字串，直接返回，无公共前缀
		if len(strs[i]) == 0 {
			return ""
		}
		lenAdd = lenAdd + len(strs[i])
		indexArr = append(indexArr, lenAdd )
	}
	longStr := strings.Join(strs, "")
	move := 0
	isBreak := 0
	fmt.Println(longStr)
	fmt.Println(indexArr)
	for {
		// 如果偏移 超过了longstr的长度
		if (indexArr[len(indexArr)-1] + move) >= len(longStr) {
			break
		}
		for j := 0; j < len(indexArr) - 1; j++ {
			if indexArr[j] + move >= indexArr[j+1] {
				isBreak = 1
				break
			}
			if longStr[indexArr[j] + move] !=  longStr[indexArr[j+1] + move] {
				isBreak = 1
				break
			}
		}
		if isBreak == 1 {
			break
		}
		// 偏移量
		move ++ 
	}
	fmt.Println(move)
	// fmt.Println(longStr[:move])
	return longStr[:move]
}
```