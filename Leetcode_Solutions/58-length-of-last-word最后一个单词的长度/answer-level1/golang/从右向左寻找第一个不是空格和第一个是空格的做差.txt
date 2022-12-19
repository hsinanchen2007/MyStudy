![image.png](https://pic.leetcode-cn.com/2fdcb6e0340f5a01181718088ae1777ae7d86be90e9b10051a0d09ecf27f93b2-image.png)

```
func lengthOfLastWord(s string) int {
    if len(s) == 0 {
		return 0
	}
	var l int = 0
	var r int = len(s) - 1
    //s1 从右向左找第一个不为空格的
	for r >= 0 {
		if s[r] == 32 {
			r--
		} else {
			break
		}
	}
    //s2 将数组最大索引设为右边第一个不为空格的索引
    // 从右边第一个不为空格的索引向左查找第一个为空格的索引
	l = r
	for l >= 0 {
		if s[l] == 32 {
			break
		}
		l--
	}
    // s3 求差
	return r - l
}
```

