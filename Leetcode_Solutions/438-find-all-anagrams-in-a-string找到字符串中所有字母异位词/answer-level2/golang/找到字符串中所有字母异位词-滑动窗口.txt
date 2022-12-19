### 解题思路

滑动窗口
1. 定义l, r窗口左右边框，窗口中匹配次数
2. r右移，判断窗口内元素是否满足『包含p中所有字符』条件，若包含，则记下当前左边框下标。持续右移，注意判断右边框是否超出字符串s右边界退出条件
3. l左移，缩小窗口，判断当前窗口内元素是否满足『包含p中所有字符』条件
 	 4.1 若包含, 则判断当前窗口长度是否与p长度相等，是则记录下当前左边下标l，左移l时要注意下标l的字符影响匹配次数及窗口内字符出现次数
	 4.2 不包含则继续步骤2

### 代码

```golang
func findAnagrams(s string, p string) []int {
    lenS, lenP := len(s), len(p)
	l, r, match := 0, 0, 0
	needMap, windowMap := make(map[string]int), make(map[string]int)

	// 填充needMap
	for i := 0; i < lenP; i++ {
		word := string(p[i])
		needMap[word]++
	}

	ans := []int{}

	for r < lenS {
		rCur := string(s[r])
		// 右边框r当前字符rCur为neeeMap中所需字符
		if needMap[rCur] > 0 {
			windowMap[rCur]++
			if windowMap[rCur] == needMap[rCur] {
				match++
			}
		}

		// 右边框r右移
		r++

		// 符合题意s中所遇哦使p的字母异位词的子串
		for match == len(needMap) {
			// 如果当前窗口长度 == len(p)
			if r-l == lenP {
				ans = append(ans, l)
			}

			lCur := string(s[l])
			// 左框将向右移，若当前左框字符为符合题意字符，则需要在windowMap中减1
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

    return ans
}
```