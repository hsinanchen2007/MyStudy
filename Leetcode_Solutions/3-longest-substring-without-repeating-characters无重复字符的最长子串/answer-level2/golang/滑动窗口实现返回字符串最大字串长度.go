### 解题思路
使用滑动窗口，
（1）移动右边界，判断窗口中是否有和右边界重复字串，如果有则返回该字符的位置，赋给左边界并加1保证窗口中的字符串为非重复子串
（2）记录窗口大小
（3）返回最大窗口值

### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    var length int
    left := 0
    right := 0
    window := s[left:right]
    for ; right<len(s); right++{
        if index:=strings.IndexByte(window, s[right]);index != -1{
            left += index +1
        }
        window = s[left:right+1]
        if len(window) > length{
            length = len(window)
        }
    }
    return length
}
```