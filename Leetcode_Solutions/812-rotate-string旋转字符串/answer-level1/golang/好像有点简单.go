### 解题思路
此处撰写解题思路

### 代码

```golang
func rotateString(A string, B string) bool {
    if len(A)!=len(B){
        return false
    }
	if strings.Contains(A+A,B){
		return true
	}
	return false
}
```