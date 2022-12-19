### 解题思路
#### 按照题解的码 （中心扩展法）


### 代码

```golang
func longestPalindrome(s string) string {
	if len(s) < 1  {
		return ""
	}
	start, end := 0, 0
	for i := 0; i < len(s); i++ {
		len1 := expandAroundCenter(s, i, i)
		len2 := expandAroundCenter(s, i, i + 1)
		lenn := Max(len1, len2)
		if lenn > end - start {
			start = i - (lenn - 1) / 2
			end = i + lenn / 2
		}
	}
	return s[start:end + 1]
}

func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}


func expandAroundCenter(s string, l int, r int) int {
	for {
		if l >= 0 && r < len(s) && s[l] == s[r] {
			l--
			r++
		} else {
			break;
		}
	}
	return r - l - 1
}
```