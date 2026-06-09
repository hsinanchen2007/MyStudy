# 解析
```go
/*
====================================================
76. 最小覆盖子串
Url: https://leetcode-cn.com/problems/minimum-window-substring/
Tags: [双指针, 滑动窗口, hashMap]
Date: 2020-03-06

核心是，使用左右双指针，优先滑动右指针，直到包含了所有的所需字符串。然后左指针开始滑动，直到遇到第一个所需字符串，不符合需求，继续滑动右指针。
====================================================
*/

func MinWindow(s string, t string) string {
	var left, right, match int
	var res string
	targetMap, currMap := map[byte]int{}, map[byte]int{}

	// 处理目标字母的数组
	for i := 0; i < len(t); i++ {
		targetMap[t[i]]++
	}

	for right < len(s) {
		// 寻找字符
		if _, ok := targetMap[s[right]]; ok {
			currMap[s[right]]++
			if currMap[s[right]] == targetMap[s[right]] {
				match++
			}
		}

		right++

		// 如果达到 match 的字符个数，处理 left 指针
		for match == len(targetMap) {
			if len(res) > right-left || res == "" {
				res = s[left:right]
			}
			if v, ok := targetMap[s[left]]; ok {
				currMap[s[left]]--
				if currMap[s[left]] < v {
					match--
				}
			}
			left++
		}
	}

	return res

}

```

# 测试用例
```go
func Test_MinWindow(t *testing.T) {
	var fibTest = []struct {
		inputText   string
		inputTarget string
		expected    string
	}{
		{"ADOBECODEBANC", "ABC", "BANC"},
		{"aaaaaaaaaaaabbbbbcdd", "abcdd", "abbbbbcdd"},
		{"aaaaaaaadbcdd", "aaab", "aaadb"},
	}

	for _, tt := range fibTest {
		actual := MinWindow(tt.inputText, tt.inputTarget)
		if fmt.Sprintf("%v", actual) != fmt.Sprintf("%v", tt.expected) {
			t.Errorf("MinWindows(%v, %v) = %v; expected: %v", tt.inputText, tt.inputTarget, actual, tt.expected)
		}
	}
}
```

# 疑惑
看到代码提交页面的 0ms 的代码，不过没想明白具体的逻辑。有高手的话麻烦解答一下

```go
// 0ms 的 go 代码
func MinWindowBak(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}
	hash := make([]int, 256)
	for i := 0; i < len(t); i++ {
		hash[t[i]]++
	}
	l, count, max, results := 0, len(t), len(s)+1, ""
	for r := 0; r < len(s); r++ {
		hash[s[r]]--
		if hash[s[r]] >= 0 {
			count--
		}
		fmt.Println(count)
		for l < r && hash[s[l]] < 0 {
			hash[s[l]]++ // 没看懂
			l++
		}
		if count == 0 && max > r-l+1 {
			max = r - l + 1
			results = s[l : r+1]
		}
	}

	return results
}
```