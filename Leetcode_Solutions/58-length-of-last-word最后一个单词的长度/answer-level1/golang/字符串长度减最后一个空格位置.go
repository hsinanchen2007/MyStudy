### 解题思路
此处撰写解题思路
首先将字符串首尾去空，然后遍历出最后一个空格的位置，字符串长度减去空格位置就是最后一个单词长度
### 代码

```golang
func lengthOfLastWord(s string) int {
    s = strings.TrimSpace(s)
    var loc int
    for k, v := range s {
        if string(v) == " "{
            loc = k + 1
        }
    }
    return len(s)-loc
}
```