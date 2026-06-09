```
func isPalindrome(x int) bool {
	bs := []byte(strconv.Itoa(x))
	var rx = make([]byte, len(bs))
	for i := (len(bs) - 1); i >= 0; i-- {
		rx[(len(bs)) - 1 - i] = bs[i]
	}

	if string(rx) == string(bs) {
		return true
	}
	
	return false
}
```


![image.png](https://pic.leetcode-cn.com/f7bb3fe2abd9011317f48dfb9e2baca3c35fe95bcb5610d8b6856c3561cb07eb-image.png)
