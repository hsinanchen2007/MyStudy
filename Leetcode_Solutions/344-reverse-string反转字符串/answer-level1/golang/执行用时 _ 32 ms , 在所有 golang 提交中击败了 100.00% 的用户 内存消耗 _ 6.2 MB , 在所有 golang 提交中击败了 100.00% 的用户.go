双指针
```
func reverseString(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```

![image.png](https://pic.leetcode-cn.com/81372fd9aed13fc43f3d8ed72c31e9095fe47a97d57de41dd216dcb1bcff5cf4-image.png)
