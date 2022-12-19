### 解题思路
此处撰写解题思路

### 代码

```golang

func isFlipedString(s1 string, s2 string) bool {
	if s1==s2{
		return true
	}
	if len(s1)!=len(s2){
		return false
	}
	return strings.Contains(s1+s1,s2)
}
```