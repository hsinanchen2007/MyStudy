思路：可以利用split方法，倒序拼接。切记，不要用strings的，用bytes代替，大大提升效率。

```
func reverseWords(s string) string {
	// string换成[]byte 会大大提高效率
	srcBytes := []byte(s)
	// 分组
	bytesSlice := bytes.Split(srcBytes, []byte{' '})
	var dstBytes []byte
	for i := len(bytesSlice) - 1; i >= 0; i-- {
		// 剔除[]byte{''}的元素
		if len(bytesSlice[i]) == 0 {
			continue
		}
		dstBytes = append(dstBytes, bytesSlice[i]...)
		if i > 0 {
			dstBytes = append(dstBytes, ' ')
		}
	}

	l := len(dstBytes)
	// 判断dstBytes==[]byte{''}的情况
	if l != 0 {
		if dstBytes[l-1] == ' ' {
			dstBytes = dstBytes[:l-1]
		}
	}
	return string(dstBytes)
}
```
![image.png](https://pic.leetcode-cn.com/39376599ae476e09a7dd018cb053a6bd608fa0a585f086de3c876e749829fba7-image.png)
