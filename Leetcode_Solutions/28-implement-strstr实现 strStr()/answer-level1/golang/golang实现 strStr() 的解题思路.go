### 解题思路
原生的`strings.Index(haystack, needle)`已经很简单了，如果要放弃原生来实现的话，就使用方法二或者方法三，注释里有详尽思路。

### 代码
```golang
// 方法一：
// 执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
// 内存消耗 :2.3 MB, 在所有 Go 提交中击败了100.00%/65.96%的用户
func strStr1(haystack string, needle string) int {
	return strings.Index(haystack, needle)
}

// 方法二：
// 执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
// 内存消耗 :2.3 MB, 在所有 Go 提交中击败了100.00%的用户
func strStr2(haystack string, needle string) int {
	// 统计匹配次数
	f := 0
	// 首次匹配时的索引号
	x := 0
	// 由于循环时需要根据情况变化，因此在此先初始化
	i := 0
	j := 0
	// 字符串长度
	l_haystack := len(haystack)
	l_needle := len(needle)

	// 如果字符串为空，则返回0
	if l_needle == 0 {
		return 0
	}

	// 以匹配字符串作为外层循环
	for ; i < l_needle; i++ {
		// 以待匹配字符串作为内层循环
		for ; j < l_haystack; j++ {
			// 如果内外元素相同
			if needle[i] == haystack[j] {
				// 首次匹配记录索引
				if f == 0 {
					x = j
				}
				// 下次内层循环索引从j+1开始
				j++
				// 记录匹配成功的次数
				f++

				// 如果匹配成功的次数与匹配字符串长度相同，则返回首次匹配成功的索引
				if l_needle == f {
					return x
				}
				// 结束本次内层循环
				break
			}

			// 匹配次数大于0，但本次没有匹配成功，说明之前有匹配成功的字符，但没有完成全部匹配即断开到达本步骤
			// 例如：haystack := "missshe" needle := "ssh"
			// s第一次匹配的位置在索引2，此后下一个s又在索引3匹配成功，但下一个h在索引4失败了，
			// 此时系统只能从第一次匹配成功的索引2，向后移动一位重新开始匹配，
			// 这样s第二次匹配的位置在索引3，此后下一个s在索引4匹配成功，再下一个h在索引5匹配成功了。
			if f > 0 {
				// i从-1重新技术，跳到外层循环之前会先进行一次x++的操作，这样外层的i正好又可以从0开始循环
				i = -1
				// 本首次匹配成功的索引x向前移动一位，下次内层循环的j从最新的索引开始，而不是从0
				j = x + 1
				// 匹配成功的次数重置为0
				f = 0
				break
			}
		}
	}

	return -1
}

// 方法三：
// 执行用时 :0 ms, 在所有 Go 提交中击败了100.00% 的用户
// 内存消耗 :2.3 MB, 在所有 Go 提交中击败了100.00%/63.89%的用户
func strStr3(haystack string, needle string) int {
	lHaystack := len(haystack)
	lNeedle := len(needle)

	for i := 0; i <= lHaystack-lNeedle; i++ {
		if haystack[i:i+lNeedle] == needle {
			return i
		}
	}

	return -1
}
```