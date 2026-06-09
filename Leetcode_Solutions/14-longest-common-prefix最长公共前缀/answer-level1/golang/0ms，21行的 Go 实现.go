![14t0ms.png](https://pic.leetcode-cn.com/c58e5e49679f1ffe16bad8d0edce33125befe70a74e4e839664a483e77837733-14t0ms.png)

从头比较字符串数组中的每个字符，如果遇到不相同的，说明找到了最长公共前缀

代码：
```
func longestCommonPrefix(strs []string) string {
    s := ""
    n := 0      // 字符游标，用于判断所有字符串在游标位置的字符是否都相同，游标递增
    for {
        i := 0
        for ; i<len(strs); i++ {    // 遍历字符串数组
            if n >= len(strs[i]) {  // 如果当前游标超出某个字符串的长度，退出遍历
                break
            }
            if strs[i][n] != strs[0][n] {   // 如果当前位置的字符有不相同的，退出遍历
                break
            }
        }
        if len(strs)==0 || i<len(strs) {    // 判断是否是中途退出，如果是，说明已经找到最长公共前缀，退出函数
            return s
        } else {                            // 反之，游标递增，继续看下一个字符
            s = strs[0][:n+1]
            n++
        }
    }
}
```