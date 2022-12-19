### 解题思路
go 解决字符串类问题有一个极其好用的小技巧：alias + utf8
1. go 中 byte alise uint8， rune alias int32， go中的alias标识两者具有相同的类型和计算方法，可以互相替换，其中最突出的一点就是可以+-*/计算
2. go 中所有字符都用utf8编码，也即byte在128位内与ascii编码一致

本题最长回文字符串其实求的是所有字符的最大偶数之和，再加上1
1. 定义一个能放下所有字母的arr，注意ascii中a~z与A~Z不连续，且小写字符序号大，那么定义的最大长度就是'z'-'A'，arr索引代表字母，值代表出现的次数
2. 对每个出现的字母加1
3. 如果字母出现偶数次，那么直接加到结果中，如果出现奇数，那么加到结果中后还需要减一，并记录是否有奇数出现
4. 如果有奇数出现，返回结果加1

### 代码

```golang
func longestPalindrome(s string) int {
    const size = int('z'-'A') + 1
    var charsArr [size]int  // type byte = uint8
    for i := range s {
        charsArr[s[i]-'A']++
    }
    var oddFlag bool 
    var res int
    for i := range charsArr {
        if c:=charsArr[i]; c % 2 == 0 {
            res+=c
        } else {
            res += c - 1
            oddFlag=true
        }
    }
    if oddFlag {
        res++
    }
    return res
}
```