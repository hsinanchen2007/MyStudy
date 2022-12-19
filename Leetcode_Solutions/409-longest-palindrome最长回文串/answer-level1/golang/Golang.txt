刚看到题的时候不知道怎么做，被回文吓到了。但是一想，easy的题应该好做吧，点开tag一看，好家伙，hash-table。
那就简单了呀，用一个哈希表记录每个字符出现次数，由于回文串中，最多只能有一个字符出现次数是奇数（长度为奇数的串，最中间那个字符），所以在统计玩哈希表后，遍历每个(key, value)对：
- value为偶数：直接加value
- value为奇数：加上(value-1)，设置single为true，即有奇数出现

```
func longestPalindrome(s string) int {
    size := len(s)
    if size < 2 {
        return size
    }

    count := make(map[byte]int) // 记录每个字符出现次数
    for i := range s {
        count[s[i]]++
    }

    res := 0
    single := false
    for _, v := range count {
        if v & 1 == 0 { // 是否为偶数
            res += v
        } else {
            res += v - 1 // 奇数-1 为偶数
            single = true
        }
    }

    if single {
        return res + 1
    }
    return res
}
```
