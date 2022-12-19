这题解题思路是典型的滑动窗求解，代码如下：
```
func lengthOfLongestSubstring(s string) int {
    ans := 0
    mem := make(map[byte] int) //char, location

    for left, right := 0, 0; right < len(s); right++ {
        if loc, ok := mem[s[right]]; !ok || loc < left { //不在map，或不在窗内了
            len := right - left + 1
            if len > ans {
                ans = len
            }
        } else {
            left = loc + 1
        }
        mem[s[right]] = right //不论怎样，都更新map
    }

    return ans
}
```
这里我用的是hashMap来记录滑动窗内元素对应的下标，这题由于是字符，可以用一个更小的数组，如`[256]int`代替。

