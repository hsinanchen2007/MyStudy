### 解题思路
cnts 记录s1字符串中，字符出现的次数。
然后，在s2上面进行窗口滑动：
- 如果发现滑动新增的字符，不属于s1，那么窗口重新从下一个字符开始；
- 如果新增的字符的次数为0，那么，说明当前窗口已经包含了刚好的该字符，因此，滑动窗口到左侧第一次出现该字符的位置；
- 如果新增的字符的次数大于0，说明缺失该字符，（如果刚好缺少1个，判断窗口长度和s1是否相等，返回true）；否则扩充窗口。

### 代码

```golang
func checkInclusion(s1 string, s2 string) bool {
    // record count of chars in s1
    cnts := make(map[byte]int, 26)

    for i := 0; i < len(s1); i++ {
        cnts[s1[i]]++
    }

    left := 0
    right := 0
    for right < len(s2) {
        // expand window
        cnt, ok := cnts[s2[right]]
        if !ok { // not char in s1, so begin new window
            for left < right {
                cnts[s2[left]]++
                left++
            }
            right++
            left = right
            continue
        }
        if cnt == 0 { // char in s1, but too much found
            for left < right {
                if s2[left] == s2[right] {
                    left++
                    break
                }
                cnts[s2[left]]++
                left++
            }
        } else {
            if cnt == 1 && right - left + 1 == len(s1) {
                return true
            }
            cnts[s2[right]] = cnt - 1
        }
        right++
    }
    return false
}
```