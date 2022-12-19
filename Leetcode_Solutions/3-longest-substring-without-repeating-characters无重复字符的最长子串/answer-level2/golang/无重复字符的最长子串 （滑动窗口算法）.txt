### 解题思路
使用滑动窗口思路
start 是窗口的开始
end 是窗口的结束索引+1
lookup 记录当前窗口中的字符的重复次数（理论上只能是[0,2]）。

当遇见当前字符在窗口中出现过时（ok && res>0）。重新计算start。把和当前窗口中和当前字符相等的字符及前面字符减去1。
同时每去掉一个字符start+1（相当于窗口向右滑动一次）
### 代码

```golang
func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	start := 0
	end := 0
	maxLen := 0
	lookup := make(map[int32]uint8)

	for _,c:=  range s {
		res,ok := lookup[c]
		// 包含,窗口中已经去除的不算包含
		if ok && res>0 {
			flag := false
			lookup[c] += 1
			for ;; {
				// 跳到上一个 和当前字符串相同的点
				if int32(s[start]) == c {
					flag = true
				}
				lookup[int32(s[start])] -= 1
				start += 1
				// 没有找到上一个相同的字符，继续。
				if !flag {
					continue
				}
				// 发现了上一个和当前字符相同的字符，退当前循环。
				break
			}
		} else { // 不包含
			lookup[c] = 1
		}
		end += 1
		if maxLen < end - start {
			maxLen = end - start
		}
	}

	return maxLen
}
```