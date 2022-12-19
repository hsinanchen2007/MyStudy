### 解题思路
此处撰写解题思路

### 代码

```golang
func isPalindrome(s string) bool {

	var resStr []byte

	for i := 0; i < len(s); i++ {
		var code byte
		code = s[i]
		//fmt.Println("s[i] == ", s[i])
		if s[i] > 90 {
			code = s[i] - 32
		}
		if (code >= 65 && code <= 90) || (code >= 48 && code <= 57) {
			resStr = append(resStr, code)
		}
	}
    if len(resStr) == 0 {
        return true
    }

    fmt.Println(resStr)
    num := len(resStr) - 1
    
    // fmt.Println(resStr[0], resStr[num])
    for i := 0; i < len(resStr) / 2; i++ {
        fmt.Println(resStr[i], resStr[num])
        if resStr[i] == resStr[num] {
            num--
        }else {
            return false
        }
    }
    return true


}
```