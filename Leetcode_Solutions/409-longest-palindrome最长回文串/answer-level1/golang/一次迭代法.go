### 解题思路
思想就是看凑对的个数，然后再判断是否有奇个数，最后转换一下

### 代码

```golang
// 思想就是看凑对的个数，然后转换一下
func longestPalindrome(s string) int {
    if s == "" {
        return 0
    }
    // 注意这里是 rune 类型，非 byte，另由于我的这种思路不会超过2，所以累计个数只要定义byte就可以了
    charMap := make(map[rune]byte, len(s))
    cnt := 0
    for _, c := range s {
        // 如果它在 map 已经计数一个了，那么刚好可以凑一对了
        if charMap[c] > 0 {
            // 此时，清计数
            charMap[c]--
            // 记录有几对
            cnt++
        }else{
            // 之前不存在，就计一次
            charMap[c]++
        }
    }
    // 总长度相等，就说明凑对满了
    if cnt*2 == len(s) {
        return 2*cnt
    }
    return 2*cnt+1
}
```