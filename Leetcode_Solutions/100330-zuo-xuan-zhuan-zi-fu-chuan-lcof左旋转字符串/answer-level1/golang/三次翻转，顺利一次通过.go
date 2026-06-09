### 解题思路
先分段翻转前后两段字符串，然后整体翻转

### 代码

```golang
func reverseLeftWords(s string, n int) string {
    // 先做分别翻转，然后再整体翻转
    l := len(s)
    n = n % l
    if n == 0 {
        return s
    }
    str := []byte(s)
    reverse(str, 0, n - 1)
    reverse(str, n, l - 1)
    reverse(str, 0, l - 1)
    return string(str)
}

func reverse(str []byte, start, end int) {
    l := len(str)
    if l <= 1 {
        return
    }
    if start >= end {
        return
    }
    for start < end {
        str[start], str[end] = str[end], str[start]
        start++
        end--
    }
}
```