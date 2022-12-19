golnag实现，１．反转整个数字；２．反转一半数字．

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)

1.反转整个数字

```go
// 反转整个数字（反转过程中可能溢出）
// 时间复杂度：O(log10(n))　　空间复杂度：O(1)

func isPalindrome(x int) bool {

	if x<0 {
		return false
	}
	
	y := 0
	z := x
	for x>0 {
		y = 10*y + x%10
		x /= 10
	}

	return z==y
}
```


2.反转一半数字

```
// 反转一半的数字
// 时间复杂度：O(log10(n))　　空间复杂度：O(1)

func isPalindrome(x int) bool {

	if x<0 || (x%10==0 && x!=0) {
		return false
	}
	
	y := 0
	for x>y {
		y = 10*y + x%10
		x /= 10
	}

	return x==y || x==y/10
}
```

