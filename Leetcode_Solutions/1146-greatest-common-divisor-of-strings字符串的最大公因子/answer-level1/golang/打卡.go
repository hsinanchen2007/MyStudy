### 解题思路
辗转相除法

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
    if !((str1 + str2) == (str2 + str1)) {
            return "";
    }
    
    return str1[0:gcd(len(str1), len(str2))];
}

func gcd(a, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}
```