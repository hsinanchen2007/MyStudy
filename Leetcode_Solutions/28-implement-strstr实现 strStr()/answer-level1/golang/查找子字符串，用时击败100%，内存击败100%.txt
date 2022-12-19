### 解题思路
3个思路解题
1. 思路1：直接使用标准库的方法 strings.Index，个人推荐。省时省力效率高，编程不二之选；
2. 思路2：先把边界抛出。此时先获取长度差，差值就是遍历的范围了。此时在目标字符串上截图子字符串，判断是否与needle相等，如果相等返回当前的 遍历index；
3. 思路3：则是双层遍历，逐个字符比较，不推荐，所以代码没列举

### 代码

```golang
//思路1的解法
func strStr(haystack string, needle string) int {
    return strings.Index(haystack, needle)
}
```

```golang
//思路2的解法
func strStr2(haystack string, needle string) int  {
	//needle为空，返回0，惯例
	if needle == ""{
		return 0
	}
	//haystack为空，返回-1；如果haystack长度小于needle，返回-1，都是惯例
	if haystack == "" || len(haystack) < len(needle){
		return -1
	}

	//needle长度
	subLen := len(needle)
	//求出的差值代表遍历的范围，如果超出此值，再从haystack截取出来的字符串肯定比needle短（就是不相等）
	beginLen := len(haystack) - subLen

	for i := 0; i < beginLen; i++ {
		if haystack[i:i+subLen] == needle {
			return i
		}
	}
	return 0
}
```
