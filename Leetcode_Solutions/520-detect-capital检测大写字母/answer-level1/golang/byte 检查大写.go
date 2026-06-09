### 解题思路
byte 检查大写
### 代码

```golang
func detectCapitalUse(word string) bool {
    upperCaseCount := 0
    n := len(word)
    isFirstUpperCase := false
    for i:=0;i<n;i++{
        upperCaseCount += upperCase(word[i])
        if i== 0 && upperCaseCount == 1{
            isFirstUpperCase = true
        }
    }
    if upperCaseCount == 0 {
        return true
    }
    if upperCaseCount == n{
        return true
    }
    if isFirstUpperCase && upperCaseCount ==1 {
        return true
    }
    return false

}

func upperCase( b byte)int{
    if b>= 'A' && b <='Z'{
        return 1
    }
    return 0
}
```