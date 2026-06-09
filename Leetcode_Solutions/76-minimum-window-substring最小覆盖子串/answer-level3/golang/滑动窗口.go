### 解题思路
滑动窗口算法的思路是这样：

**滑动窗口 + map存字符以及初选的次数**

1、我们在字符串 S 中使用双指针中的左右指针技巧，初始化 left = right = 0，把索引闭区间 [left, right] 称为一个「窗口」。

2、我们先不断地增加 right 指针扩大窗口 [left, right]，直到窗口中的字符串符合要求（包含了 T 中的所有字符）。

3、此时，我们停止增加 right，转而不断增加 left 指针缩小窗口 [left, right]，直到窗口中的字符串不再符合要求（不包含 T 中的所有字符了）。同时，每次增加 left，我们都要更新一轮结果。

4、重复第 2 和第 3 步，直到 right 到达字符串 S 的尽头。

这个思路其实也不难，第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动。

### 代码

```golang
func minWindow(s string, t string) string {
	var left, right, match, minLen, l, resL, resR int
	tt := []byte(t)
	needs := make(map[byte]int, len(t))
	windows := make(map[byte]int, len(t))
	for _, v := range tt {
		needs[v]++
	}
	for right <= len(s)-1 {
		// 是子串的内容
		if _, ok := needs[s[right]]; ok {
			// 窗口中字符  对应 数加一
			windows[s[right]]++
			// 匹配了某个字符
			if windows[s[right]] == needs[s[right]] {
				match++
			}
		}

		// 全部匹配
		for match == len(needs) {
			l = right - left+1

			if minLen==0||l < minLen {
				resL = left
				resR = right
				minLen = l
			}

			// left边界是子串中的字符，则要计算
			if _, ok := needs[s[left]]; ok {
				// 窗口中字符  对应 数减一
				windows[s[left]]--
				if windows[s[left]] < needs[s[left]] {
					match--
				}
			}
			left++
		}
		right++
	}
	if minLen == 0 {
		return ""
	}
	return s[resL : resR+1]
}
```