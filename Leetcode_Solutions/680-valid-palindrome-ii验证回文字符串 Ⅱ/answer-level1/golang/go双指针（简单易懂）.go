```
func validPalindrome(s string) bool {
  return doValidPalindrome(s,0,len(s)-1,0)
}

func doValidPalindrome(s string,l,r int,k int) bool{
	for l<r{
		if s[l]==s[r]{
			l++
			r--
		}else if k==0{
			return doValidPalindrome(s,l+1,r,k+1)||doValidPalindrome(s,l,r-1,k+1)
		}else {
			return false
		}
	}
	return true
}
```
