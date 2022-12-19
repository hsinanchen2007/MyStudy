### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 Go 提交中击败了
100.00%
的用户
内存消耗 :
2.1 MB
, 在所有 Go 提交中击败了
100.00%
的用户
1、利用map，判断出现奇数次的字符是否只有一个，如果有一个那么就true 否则 false
### 代码

```golang
func canPermutePalindrome(s string) bool {
    
    strMap := make(map[string]int)

    for i := 0; i < len(s); i++ {
        strMap[string(s[i])]++
    }

    count := 0
    for _, v := range strMap {
        if v % 2 == 1 {
            count++
            if count > 1 {
                return false
            }
        }
    }
    return true
}
```