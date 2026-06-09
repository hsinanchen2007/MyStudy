### 解题思路
map解法：依次遍历前0~n-2个字符的每一个，如果前一个小于后一个，总和减去前一个对应的数，否则加上前一个对应的数，最后加上第n-1个字符对应的数，返回结果即可。

### 代码

```golang
func romanToInt(s string) int {
    hash := map[byte]int{
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    }
    result := 0
    for i:=0;i<len(s)-1;i++{
        if hash[s[i]] < hash[s[i+1]] {
            result -= hash[s[i]]
        } else {
            result += hash[s[i]]
        }
    }
    result += hash[s[len(s)-1]]
    return result
}
```