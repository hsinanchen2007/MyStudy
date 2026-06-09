**终止条件**
在两个字符串长度相等的时候，进入最终阶段。
- 如果两个字符串完全相等，则返回该字符串。
- 如果两个字符串不相等，则返回空字符串。

**缩小参数规模**
如果两个字符串长度不相等，则让str1长度大于str2。
判断str2是否为str1的子集，如果是，则使用str1剩余的部分和str2继续进行比较。
直到两者长度相等，进入终止条件。

``` go
func gcdOfStrings(str1 string, str2 string) string {
	l1 := len(str1)
	l2 := len(str2)
	if l1 < l2 {
		return gcdOfStrings(str2, str1)
	}

	if l1 == l2 {
		if str1 == str2 {
			return str1
		}

		return ""
	}

	for i := 0; i < l2; i++ {
		if str1[i] != str2[i] {
			return ""
		}
	}

	return gcdOfStrings(str1[l2:], str2)
}
```
