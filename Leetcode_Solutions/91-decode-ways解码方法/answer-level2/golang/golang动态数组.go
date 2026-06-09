用变量cur表示当前字符串长度的最多译码方法数量，由于每次遍历cur的取值之和前两次有关，所以每次遍历开始的时候cur,past分别表示上一次和上上一次动态规划值。没有必要申请切片或者数组，这样空间复杂度就位O(1).
注意特殊情况就是当字符串第一个字母为0时，直接返回0，因为无法解码这种情况
```
func numDecodings(s string) int {
	pre, cur := 1, 1
	if s[0:1] == "0" {
		return 0
	}
	for i := 1; i < len(s); i++ {
		ttmp := cur
		if s[i:i+1] == "0" {
			if s[i-1:i] == "1" || s[i-1:i] == "2" {
				cur = pre
			} else {
				return 0
			}
		} else if s[i-1:i] == "1" {
			cur = cur + pre
		} else if s[i-1:i] == "2" {
			if s[i:i+1] < "7" {
				cur = cur + pre
			}
		}
		pre = ttmp
	}
	return cur
}
```
