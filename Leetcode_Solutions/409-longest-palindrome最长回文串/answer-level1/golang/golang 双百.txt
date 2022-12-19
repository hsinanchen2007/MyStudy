### 解题思路
核心思想：哈希表获得字母出现次数
注意事项：数组长度，了解 ASCII 码表中，大小写字母的位置

### 代码

```golang
func longestPalindrome(s string) int {
    var counts ['z'-'A'+1]int

    for _, m := range s {
        counts[m -'A']++
    }
    res := 0
    isFirst := true
    for _, m := range counts {
        if m > 0 && m & 1 == 0 {// 大于 0 的偶数，直接加
            res += m
        }else if (m > 1) && (m & 1 == 1) {// 大于 1 的奇数：回文串中奇数个数的字母最多有一个
            if isFirst {
                res += m 
                isFirst = false
            }else {
                res += m - 1
            }
        }else if m == 1 && isFirst{
            res += 1
            isFirst = false
        }
    }
    return res
}
```