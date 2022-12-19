### 解题思路
Go 双指针

### 代码

```golang
// 双指针 O(n) O(1)

func validPalindrome(s string) bool {
    byteS:=[]byte(s)
    i, j:= 0 , len(byteS) -1
    for i<j {
        if byteS[i] != byteS[j] {
            return isPalindrome(byteS,i+1,j) || isPalindrome(byteS,i,j-1)
        }
        i++
        j--
    }
    return true
}

func isPalindrome(s[]byte, i, j int) bool {
    for i<j {
        if s[i] != s[j] {
            return false
        }
        i++
        j--
    }
    return true
}
```