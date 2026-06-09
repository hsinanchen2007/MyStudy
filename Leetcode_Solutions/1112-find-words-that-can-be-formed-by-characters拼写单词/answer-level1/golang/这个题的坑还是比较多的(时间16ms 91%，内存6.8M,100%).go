### 解题思路
![image.png](https://pic.leetcode-cn.com/138dcb66fb87fc9a4eb789616d96a69c4e4f42c6d3284670eda74956162cccae-image.png)

这个题看起来很简单，其实也很简单，唯一的坑在于chars中只能用一次，所以做个count计算就行
这里也能用到go语言的多层循环跳转，如果别的语言怕是需要更多的标志位和判断。，
下面的代码的注释很详细了。
更快的解决方案：不穷举字母，而是看有哪些字母，我的代码里是穷举这个单词所有字母，
但是单词中的字母肯定是重复的，但是如果map可以空间换时间。

### 代码

```golang
func countCharacters(words []string, chars string) int {
	// chars中的只能用一次
	var wholeLength int = 0
	outloop: for _, v1 := range words {
		// 拿每一个单词。
		for _, v2 := range v1{
			// 取字母
			if strings.Count(v1, string(v2)) > strings.Count(chars, string(v2)) {
				// 如果在单词中某个字母的数量大于词库中的数量，说明弄不了。
				continue outloop
			}
		}
		// 如果这个循环走完了，能走到这里，说明这个单词里的字母都在chars中
		wholeLength += len(v1)
	}
	return wholeLength
}
```