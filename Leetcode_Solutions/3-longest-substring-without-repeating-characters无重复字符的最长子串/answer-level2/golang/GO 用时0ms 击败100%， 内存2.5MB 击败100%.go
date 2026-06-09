### 解题思路
![捕获.JPG](https://pic.leetcode-cn.com/b19e2a36e75231832c0d88a775fdbcc59da50df69b53aaf3ee8fb331f5f5af87-%E6%8D%95%E8%8E%B7.JPG)
看大佬的题解理解了滑动窗口的妙用
自己写了个尽量简洁的
提交了两次，竟然全击败了2333
### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    length, left, right := 0, 0, 0
	lenS := len(s)
	for ;right < lenS; right++ {
		sCur := s[left: right]
		index := strings.IndexByte(sCur, s[right])
		if  index != -1 {
			left += index + 1
		} else {
			curLength := right - left + 1
			if length < curLength {
				length = curLength
			}
		}
	}
	return length
}
```