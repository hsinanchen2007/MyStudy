### 解题思路
字典存储当前字符的索引，因此下次碰到相同字符可以直接滑动窗口到该索引。
同时需要记住，这种滑动需要注意碰撞字符需要在窗口内，不在窗口内的直接忽略。

### 代码

```golang
import "fmt"

func lengthOfLongestSubstring(s string) int {
    start := 0
    maxLength := 0
    m := make(map[rune]int)

    for end, c := range s {
        if prevIdx, ok := m[c]; ok && prevIdx >= start {
            start = prevIdx + 1
        } else {
            if currentLength := end - start + 1; maxLength < currentLength {
                maxLength = currentLength
            }
        }
        fmt.Printf("%c, %d\n", c, maxLength)
        m[c] = end
    }
    return maxLength
}

```