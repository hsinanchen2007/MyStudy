### 参考文献

关于更快的判断奇偶数的方法可以参考[这里](https://github.com/LZH139/leetcode_Go/blob/master/guide/%E6%8F%90%E9%80%9F%E5%B0%8F%E6%8A%80%E5%B7%A7.md)

### 解题思路

如果要能形成回文数，那么出现次数为奇数的字母最多只能有一个。

遍历的同时用数组记录每个字符出现的个数，然后再次遍历数组计算出现次数为奇数的字母的个数，只有一个或者零个才能组成回文字符


### 参考代码

```
func canPermutePalindrome(s string) bool {
    var list [128]int
    length := len(s)
    for i:=0;i<length;i++ {
        list[s[i]]++
    }
    count:=0
    for i:=0;i<128;i++{
        if list[i] & 1 == 1 {
            count++
        }
    }
    return count == 1 || count == 0
}
```




