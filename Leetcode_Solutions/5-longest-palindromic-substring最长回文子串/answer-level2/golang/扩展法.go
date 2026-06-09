### 解题思路
此处撰写解题思路

### 代码

```golang
func longestPalindrome(s string) string {
    result := ""
    for i:=0; i < len(s); i++{
        leftStr := expandStr(s,i,i)
        rightStr := expandStr(s,i,i+1)
        if len(leftStr) > len(result){
            result = leftStr
        }
        if len(rightStr) > len(result){
            result = rightStr
        }
    }
    return result
}

func expandStr(s string, left,right int) string{
    for ;left > -1 && right < len(s) && s[left] == s[right];{
        left--
        right++
    }
    return s[left+1:right]
}
```