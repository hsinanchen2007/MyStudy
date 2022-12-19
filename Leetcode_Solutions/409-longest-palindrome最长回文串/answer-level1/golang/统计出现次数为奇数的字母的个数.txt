### 解题思路
遍历字符串，统计每个字母的出现次数
然后计算出现次数为奇数的字母个数odd。
当其不超过1时，最大回文串长度就是给定字符串长度；
否则要去掉odd - 1个字母才能构造回文字符串。

### 代码

```golang
func longestPalindrome(s string) int {
    up := [26]int{} // 统计大写字母出现次数
    low := [26]int{} // 统计小写字母出现次数

    for i := 0; i < len(s); i++ {
        if s[i] >= 'a' && s[i] <= 'z'{
            low[int(s[i] - 'a')]++
        } else if s[i] >= 'A' && s[i] <= 'Z'{
            up[int(s[i] - 'A')]++
        }
    }
    odd := 0
    for i := 0; i < 26; i++ {
        if up[i] % 2 == 1 {
            odd++
        }
        if low[i] % 2 == 1 {
            odd++
        }
    }
    
    if odd > 1 {
        return len(s) - odd + 1
    } else {
        return len(s)
    }
}
```