### 解题思路
此处撰写解题思路

### 代码

```golang
func validPalindrome(s string) bool {

	for i,j:=0, len(s)-1;i<=j;{
		if s[i]!=s[j]{
			str:=[]rune(s)
			return findValidPalindrome(str,i+1,j)||findValidPalindrome(str,i,j-1)
		}
		i++
		j--
	}
	return true
}
func findValidPalindrome(s []rune,i, j int) bool{
	for i<=j{
		if s[i]!=s[j]{
			return false
		}
		i++
		j--
	}
	return true
}
```