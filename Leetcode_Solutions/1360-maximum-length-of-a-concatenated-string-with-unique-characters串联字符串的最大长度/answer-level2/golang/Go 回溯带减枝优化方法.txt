这道题刚开始拿到手时，也是手足无措，不知何解？
- 考虑过将字符串两两处理得到重复的字符数，然后把每个字符串抽象成图中的点，把有重复字符的字符串连接起来，构成一幅图，然后我就懵逼了。这法子行不通！！！
- 后面参考了别人的题解中的思想：**对于字符串数组中的每个字符串你可以选或不选，这就可以看成一种排列组合的思想，枚举出所有的组合情况(总共2^n种可能)，最终找到不含重复字符的最长的合成字符串。**
- 在算法实现上，基本上就是使用**map**来处理是否包含重复字符的问题，然后寻找符合条件的最长字符串就是通过**递归**去实现。
- 最后在代码上加些剪枝优化，就能过了。
- 考试时，没有做出这道题真的很懊恼啊！总结一下还是自己抽象问题的能力不够！

```go
func maxLength(arr []string) int {
	maxLenStr := dfs("", arr, 0, len(arr)-1)
	return len(maxLenStr)
}

// 检查字符串中是否有重复字符
func checkUniq(str string) bool {
	if len(str) == 0 {
		return true
	}

	countMap := make(map[byte]int)
	for i := 0; i < len(str); i++ {
		if countMap[byte(str[i])] > 0 {
			return false
		}
		countMap[byte(str[i])]++
	}

	return true
}

// dfs: str为组合后的字符串，arr为输入的字符串数组，start为当前正在处理的字符串索引，end为字符串数组最后一个位置的索引
func dfs(str string, arr []string, start, end int) string {
	// 减枝操作：根据字符串中都是小写字母的特性，如果字符串长度大于26，说明一定有重复字符
	if len(str) > 26 {
		return ""
	}
	// 递归结束条件：处理完字符串数组最后一个字符串之后
	if start > end {
		// 此时的str就是字符串就是最终合成的字符串
		// 检查其是否符合无重复字符的要求
		if checkUniq(str) {
			return str
		}
		return ""
	}

	// 当处理start位置的字符串时我们有两种选择，一种是不把arr[start]加入到合成的字符串中
	// 另外一种就是把arr[start]加入到合成的字符串中，然后继续进行dfs搜索，找到符合不重复条件
	// 并且长度最长的合成字符串的组合
	noAddStr := dfs(str, arr, start+1, end)
	addStr := ""
	// 这里进行一个减枝的操作，加入当前str+arr[start]合成的字符串中已经有重复字符了，那就没必要
	// 继续调用dfs搜索了
	if checkUniq(str + arr[start]) {
		addStr = dfs(str+arr[start], arr, start+1, end)
	}

	// 返回合成字符串最长的那个
	if len(noAddStr) > len(addStr) {
		return noAddStr
	}
	return addStr
}
```
