golang 中心扩展算法

github: https://github.com/Crownt/leetcode

```
// 中心扩展算法，对于奇数长度和偶数长度，分别以[i,i],[i,i+1]为回文串的中心向两端扩展
// 时间复杂度：O(n^2)  空间复杂度：O(1)

var longest_palindrome string

func longestPalindrome(s string) string {

	longest_palindrome = ""
	for i:=0;i<len(s);i++ {
		getPalindrome(s, i, i)
		getPalindrome(s, i, i+1)
	}

	return longest_palindrome
}

func getPalindrome(s string, i int, j int) {

	for i>=0 && j<len(s) && s[i:i+1]==s[j:j+1] {
		if len(s[i:j+1])>len(longest_palindrome) {
			longest_palindrome = s[i:j+1]
		}
		i--
		j++
	} 	
}
```
