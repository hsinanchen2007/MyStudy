### 解题思路
此处撰写解题思路
1、拿到题先找规律
2、把边界写好
3、搞个map，把每个字符出现的次数存起来，字符出现偶数次直接在res上相加，如果是奇数次，就在奇数次-1再加上res

### 代码

```golang
func longestPalindrome(s string) int {
    if (len(s) <= 1) {
        return len(s)
    }
    strMap := make(map[string]int)
    for i:=0;i<len(s);i++{
        strMap[string(s[i])]++
    }
    res := 0
    boolRes := false
    for _,v:=range strMap{
        if v % 2 == 1 {
            boolRes = true
            res = res + v - 1
        } else {
            res = res + v
        }
    }
    if boolRes {
        return res + 1
    }else {
        return res
    }
}
```