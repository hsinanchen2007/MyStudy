### 解题思路
此处撰写解题思路

### 代码

```golang
func strStr(haystack string, needle string) int {
    // 双指针
    // 空字符串
    if needle == "" {
        return 0
    }
    // 两个字符串长度
    l1 := len(haystack)
    l2 := len(needle)
    if l2 > l1 {
        return -1
    }

    // 匹配串指针
    p := 0
    for p < l1 - l2 + 1 {
        // 找到第一个相等的
        for p < l1 - l2 + 1 && haystack[p] != needle[0] {
            p++
        }
        // 开始计算长度
        curLen := 0
        // 第二个字符串指针
        q := 0
        // 相等都前进
        for q < l2 && p < l1 && haystack[p] == needle[q] {
            q++
            p++
            curLen++
        }
        // 匹配完全则返回
        if curLen == l2 {
            return p - l2
        }
        //否则后退回去
        p = p - curLen + 1
    }
    return -1
}

```