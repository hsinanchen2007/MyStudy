思路：为了效率，不用split方法，而用双指针。

```
func reverseWords(s string) string {
	sLen := len(s)
	srcBytes := []byte(s)

	var dstBytes []byte
	for i := 0; i < sLen; {
		// 寻找每一个单词的开头索引
		for srcBytes[i] == ' ' {
			i++
		}

		// 寻找每一个单词的结束索引
		indexEnd := i
		for indexEnd < sLen && srcBytes[indexEnd] != ' ' {
			indexEnd++
		}

		// 单词倒序填充
		for curIndex := indexEnd - 1; curIndex >= i; curIndex-- {
			dstBytes = append(dstBytes, srcBytes[curIndex])
		}
		dstBytes = append(dstBytes, ' ')

		// 开始下一轮搜索
		i = indexEnd
	}

	dstLen:=len(dstBytes)
	if dstLen!=0{
		// dstBytes最后一定是' ',剔除返回string
		dstBytes=dstBytes[:dstLen-1]
	}
	return string(dstBytes)
}
```
![image.png](https://pic.leetcode-cn.com/f636c6388517c177968a2761514fcdc7e764dfbe1a3032ddcffdd963062d2039-image.png)
