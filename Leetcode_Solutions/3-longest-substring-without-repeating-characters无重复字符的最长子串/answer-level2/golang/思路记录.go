### 解题思路
使用滑动窗口，性能友好
解题要点：
1. 遍历字符串，当前值与滑动窗口进行比较，如果滑动窗口内有重复位置，则只保留当前位置到最后的窗口内容
go代码操作
```golang
win = win[wk+1:]
```
2. 注意这个时候要先把当前内容push到窗口内，再进行窗口大小与最大的窗口大小比较运算，这个顺序容易范模糊

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    win := make([]uint8, 0)
	max := 0
	for i := 0; i < len(s); i++ {
		for wk, w := range win {
			if w == s[i] {
				win = win[wk+1:]
				break
			}
		}
		win = append(win, s[i])
		if len(win) > max {
			max = len(win)
		}
	}
	return max
}
```

其中win是可以在原始字符串上面复用的，代码如下：
```golang
func lengthOfLongestSubstring(s string) int {
    win := s[0:0]
	max := 0
	var (
		start, end int
	)
	for i := 0; i < len(s); i++ {
		for wk, w := range win {
			if w == int32(s[i]) {
				start = start + wk + 1
				break
			}
		}
		end += 1
		win = s[start:end]
		if len(win) > max {
			max = len(win)
		}
	}
	return max
}
```

### 暴力算法

遍历字符串，如果发现**当前位置字符串**与**之前缓存下来的字符串**有重复的，则从这个**重复位置在原始字符串的位置加1**再次循环即可。

需要牢记的一些计算：
1. 当发现重复位置，重新循环位置为：当前缓存子串的起始位置cacheStart + 在当前子串中重复位置l + 1
2. 当前子串长度计算：当前循环字符串位置k - 当前缓存子串的起始位置cacheStart + 1

**当计算子串长度的时候，索引位置相减还需要加1**

```golang
func lengthOfLongestSubstring(s string) int {
	if s == "" {
		return 0
	}
	var long int
	var cache string
	var cacheStart int
	k := 0
RESTART:
	for ; k < len(s); k++ {
		for l, c := range cache {
			if c == int32(s[k]) {
				cache = ""
				k = cacheStart + l + 1
				cacheStart = k
				goto RESTART
			}
		}
		curLong := k - cacheStart + 1
		if curLong > long {
			long = curLong
		}
		cache += fmt.Sprintf("%c", s[k])
	}
	return long
}
```