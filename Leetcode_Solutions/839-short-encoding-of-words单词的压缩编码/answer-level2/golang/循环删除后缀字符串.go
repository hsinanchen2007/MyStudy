### 解题思路
循环删除当前字符的后缀字符，最后剩下的就是可以合并的字符串
O(mn)

### 代码

```golang
func minimumLengthEncoding(words []string) int {
	tmp := make(map[string]int, 0)
	for _, value := range words {
		if _, ok := tmp[value]; !ok {
			tmp[value] = 1
		}
	}

	for _, value := range words {
		for i := 1; i < len(value); i++ {
			delete(tmp, value[i:])
		}
	}

	ans := 0

	for key, _ := range tmp {
		ans += len(key) + 1
	}

	return ans
}
```