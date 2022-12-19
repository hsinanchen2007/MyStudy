遍历text，如果头尾相同，递归计算去头去尾后的字符串，再比较最大值即可。


注意，头尾相同 长度需要+2
```
func longestDecomposition(text string) int {
    if text == "" {
        return 0
    }
	max := 1
	for i := 0; i < len(text)/2; i++ {
		if text[:i+1] == text[len(text)-i-1:] {
			max = Max(max, 2 + longestDecomposition(text[i+1:len(text)-i-1]))
		}
	}
	return max
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

```
