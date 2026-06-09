### 解题思路
1. 回文组成要么只有1个奇数字母，要么全部是偶数
2. 根据上面的规则，只需要先计算出所有偶数长度，然后检测是否存在奇数情况，存在+1；否则返回计算的偶数值

### 代码

```golang
// 1. 最多只能有一个字符是奇数
func longestPalindrome(s string) int {
    sMap := make(map[string]int)
    for _, c := range s {
        if val, ok := sMap[string(c)]; ok {
            sMap[string(c)] = val + 1
        } else {
            sMap[string(c)] = 1
        }
    }

    // 最大的奇数长度
    haveOdd := false
    // 所有的偶数长度
    even := 0
    // 最大长度
    maxLen := 0
    for _, val := range sMap {
        // // 算出所有偶数和
        even += (val>>1)<<1
        if val % 2 != 0 {
            haveOdd = true
        }
    }

    if haveOdd { // 有偶数，补1
        maxLen = even + 1
    } else {
        maxLen = even
    }
    
    return maxLen
}
```