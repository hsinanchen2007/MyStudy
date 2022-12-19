
官方题解思路，go实现

![image.png](https://pic.leetcode-cn.com/c3468023aa49e7575675db00ca3264ca37c60c0e0ac6bc609f750a12bd4027b9-image.png)

```
func isValid(s string) bool {
    	if len(s) == 0 {
		return true
	}
	if len(s)%2 != 0 {
		return false
	}
	var arr []byte
	
	var m = map[byte]byte{')': '(', ']': '[', '}': '{'}
	
	for i := 0; i < len(s); i++ {
		// 40，91，123 分别表示 '(','[','{' 
		if s[i] == 40 || s[i] == 91 || s[i] == 123 {
			arr = append(arr, byte(s[i]))
		} else {
			if len(arr) > 0 {
				flag := arr[len(arr)-1]
				if m[byte(s[i])] != flag {
					return false
				}
				arr = arr[:len(arr)-1]
			} else {
				return false
			}
		}
	}
	if len(arr) <= 0 {
		return true
	} 
    return false
}
```



