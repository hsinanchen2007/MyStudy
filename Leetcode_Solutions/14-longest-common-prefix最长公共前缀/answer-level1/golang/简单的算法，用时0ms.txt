### 解题思路

    找出最短的字符串的长度为minl
    然后从前两个字符串比较得到<minl的最长的公共前缀pre， 此时minl = len(pre) // 注意字符串数字可能只有一个甚至是零个
    然后继续找出剩下未比较字符串和pre的最长公共前缀，直到最后全部比较完成

    分治之后比较次数不变，所以无需分治


### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    if len(strs) == 1{
        return strs[0]
    }

    ss := strs
    minl := len(ss[0])

    // 找最短长度字符串
    for _, s := range ss {
        l := len(s)
        if minl > l {
            minl = l
        }
    }

    result, minl := longestPrefix(ss[0], ss[1], minl)

    for i := 2; i < len(ss); i++ {
        result, minl = longestPrefix(result, ss[i], minl)
    }
    return result

}

// 找出str1和str2的最长子串
func longestPrefix(str1, str2 string, max int) (pre string, l int) {
    for i := 0; i < max; i++ {
        if str1[i] != str2[i] {
            return str1[0:i], i
        }
    }
    return str1[0:max], max
}

```