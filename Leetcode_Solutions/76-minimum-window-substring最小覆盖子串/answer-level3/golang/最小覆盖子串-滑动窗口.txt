### 解题思路
解题思路: 滑动窗口
1. 定义l, r窗口左右边框
2. r向右移动，扩大窗口，直到满足 『窗口内元素集windows{}满足 包含T所有字母的条件』，注意判断是否溢出字符串S边界
3. l开始向右移动，不断缩小窗口，判断是否满足 步骤2中条件，若满足，则判断是否需要更新最优解，需要则更新；若不满足，则重复步骤2，3

关于 『窗口内元素集windows{}满足 包含T所有字母的条件』：
可以使用两个哈希表 当作 计数器来解决。哈希表needMap记录字符串T中包含的字符及出现次数；哈希表windowMap 记录『当前窗口』中包含T中字符及出现次数，
如果widonwMap包含所有need中的键, 且这些键对应的值>= needMap中的值，则可知满足条件。

### 代码

```golang
func minWindow(s string, t string) string {
    windowMap, needMap := make(map[string]int), make(map[string]int)
	// 先填充needMap
	for i := 0; i < len(t); i++ {
		word := string(t[i])
		needMap[word]++
	}

	l, r, sLen := 0, 0, len(s)

	// 最小子串长度
	minLen := int(^uint(0) >> 1)

	// 符合题意的子串在S中的起始下标
	start := 0

	// match用来记录windowMap中已经已经有多少字符符合要求了
	var match int

	for r < sLen {
		//windowMap[string(s[r])]++
		rCur := string(s[r])
		// 右边框r当前字符为needMap中的字符
		if needMap[rCur] > 0 {
			// 当前字符需要加到windowMap
			windowMap[rCur]++
			if windowMap[rCur] == needMap[rCur] {
				// 字符rCur符合要求
				match++
			}
		}

		// 右边框右移
		r++

		// 符合题意条件『s中包含t中所有字母』
		for match == len(needMap) {
			// 是否当前最小子串
			if r-l < minLen {
				// 当前最小子串，更新start及minLen
				start = l
				minLen = r - l
			}

			lCur := string(s[l])
			// 左边框将右移1，若当前左边框字串为目标字符，则需要在windowMap中减1
			if needMap[lCur] > 0 {
				windowMap[lCur]--
				// 若当前左边框字符次数 < 该字符目标次数，则匹配的次数match需要 -1
				if windowMap[lCur] < needMap[lCur] {
					match--
				}
			}

			// 左边框右移
			l++
		}
	}

	if minLen < int(^uint(0)>>1) {
		return s[start : start+minLen]
	} else {
		return ""
	}
}
```