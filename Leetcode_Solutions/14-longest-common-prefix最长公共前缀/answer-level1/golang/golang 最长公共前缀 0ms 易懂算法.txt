执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.4 MB, 在所有 Go 提交中击败了59.14%的用户

基本原理: 以第一个字符串为基准，在其它n个字符串中找它，如果都找到了那么就直接返回基准字符串，如果在其它任意字符串中没有找到，那么把基准字符串的长度减一（削掉尾端，因为该题判断的是前缀，如果求最长公共后缀，那么削掉首端即可），再次进行查找，这样反复进行，直到找到符合要求的基准字符串或把基准字符串砍光。

``` golang
func longestCommonPrefix(strs []string) string {
    n := len(strs)
    // 输入为空直接返回空
    if n == 0 {
        return ""
    // 只输入一个字符串那么它自己就是最长公共后缀
    } else if n == 1 {
        return strs[0]   
    // 如果基准字符串是空，那么直接返回空
    } else if len(strs[0]) == 0 {
        return ""
    }
    // 最长公共前缀再长也不可能比最短的输入字符串还要长对吧。输入源越多，基准字符串不是最短字符串的可能性越大。
    // 因此进行初步优化，求输入源中最短的那个字符串长度，然后把基准字符串按该长度重新截取
    minStrLen := math.MaxInt32
    for i := 0; i < n; i++ {
        if minStrLen > len(strs[i]) {
            minStrLen = len(strs[i])
        }
    }
    prefix := strs[0][0 : minStrLen]
    // 标志位，如果为true说明在其它所有字符串中都找到了相同的前缀
    var allFound bool
    for {
        allFound = true
        // 循环其它字符串
        for i := 1; i < n; i++ {
            // 查询是否包含基准字符串，因为求的是前缀，所以index值为0
            if strings.Index(strs[i], prefix) != 0 {
                // 不包含的话削掉基准字符串的尾端以便开展下次查询工作
                prefix = prefix[0 : len(prefix) - 1]
                // 标志位置为false说明查询失败
                allFound = false
                // 跳出吧，也没必要再查其它字符串了
                break
            }
        }
        // 如果查询成功，跳出大循环，直接返回当前基准字符串就行了。所以该算法最好的情况就是第一次查询就成功。
        // 如果基准字符串都被砍光了，说明没有最长公共后缀，所以该算法的最差的情况就是最后一个字符串和基准字符串完全没有公共前缀，而中间的字符串都能找到公共前缀，这会导致循环minStrLen * (n - 1)次。
        if allFound || len(prefix) == 0 {
            break
        }    
    }
    return prefix
}
```
