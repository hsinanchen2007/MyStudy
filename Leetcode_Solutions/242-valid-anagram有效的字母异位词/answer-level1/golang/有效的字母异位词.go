### 解题思路
题目中已经说明了可以假设字符串中只包含小写字母，因此分配一个可以存放 26 个整型数值的数组 counts 用于计数。

假设 c 为 26 个小写字符之一，那么 counts[c - 'a'] 即用于存放 c 的计数，即：
counts['a' - 'a'] = counts[0]: 用于存放字符 'a' 的计数、
counts['b' - 'a'] = counts[1]: 用于存放字符 'b' 的计数、
...
counts['z' - 'a'] = counts[25]: 用于存放字符 'z' 的计数。

首先遍历字符串 s，每遍历一个字符 c，将 counts[c - 'a'] 的计数自增。
此次遍历完后，counts 中每个元素里的值就是对应字符在 s 中出现的次数。

然后遍历字符串 t，每遍历一个字符 c，将 counts[c - 'a'] 的计数自减。
此次遍历完后，counts 中每个元素里的值就是对应字符在 s 和 t 中出现次数的差值。

最后遍历 counts 数组，如果存在不等于 0 的值，则说明两个字符串里存在字符出现了不同的次数，否则说明每个字符在 s 和 t 中出现的次数相等。


### 代码

```golang
func isAnagram(s string, t string) bool {
    counts := make([]int, 26)
    for _, c := range s {
        counts[c - 'a']++
    }
    for _, c := range t {
        counts[c - 'a']--
    }

    for _, n := range counts {
        if n != 0 {
            return false
        }
    }
    return true
}
```