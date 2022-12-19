学习自[五分钟学算法](https://mp.weixin.qq.com/s/6YeZUCYj5ft-OGa85sQegw)

# 思考

这个问题在于在于怎么知道当前窗口中数量最多的字符的数量，

因为需要替换的字符就是当前窗口的大小减去窗口中数量最多的字符的数量。

最简单的方法就是把**哈希散列**遍历一遍找到最大的字符数量，

但是仔细想想如果我们每次新进元素都更新这个最大数量，且只更新一次，

我们保存的是当前遍历过的全局的最大值，它肯定是比实际的最大值大的，

我们左指针移动的条件是 `r - l + 1 - maxCount > k` ，

保存的结果是 `result = Math.max(r - l + 1, result);` 

这里maxCount 比实际偏大的话，虽然导致左指针不能移动，但是不会记录当前的结果，

所以最后的答案并不会受影响。


# Go实现

```go
func characterReplacement(s string, k int) int {
	if s == "" || len(s) == 0 {
		return 0
	}

	hash := make([]int, 26)
	l, maxCount, result := 0, 0, 0
	for r := 0; r < len(s); r++ {
		hash[s[r]-'A']++

		if maxCount < hash[s[r]-'A'] {
			maxCount = hash[s[r]-'A']
		}

		for r-l+1-maxCount > k {
			hash[s[l]-'A']--
			l++
		}

		if result < r-l+1 {
			result = r - l + 1
		}
	}
	return result
}
```