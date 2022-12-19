### 解题思路
1. 采用欧几里得求解最大公因子的方法，来求解字符串的最大公因子。[辗转相除法-维基百科](https://zh.wikipedia.org/wiki/%E8%BC%BE%E8%BD%89%E7%9B%B8%E9%99%A4%E6%B3%95)
2. 先构建字符串的取余方法，可求得一个字符串对另外一个字符串取余后的余数`remainder`。
3. 递归地实现辗转相除法，递归基为
	1. 余数`remainder` == `""`， 那么返回gcd的最大公因子为`str2`；
	2. `remainder` == `str1`，说明`str1`无法对`str2`取余，gcd返回`""`空字符串。
4. 递归入口：传入先前的`str2`和`str1`、`str2`取余后所得`remainder`作为参数，进行递归求解。

### 代码

```golang
func gcdOfStrings(str1 string, str2 string) string {
	if len(str1) < len(str2) {
		str1, str2 = str2, str1
	}
	var remainder = modOfStrings(str1, str2)
	if remainder == "" {
		return str2
	} else if remainder == str1 {
		return ""
	}
	return gcdOfStrings(str2, remainder)
}
func modOfStrings(str1, str2 string) string {
	length := len(str2)
	var remainder = str1
	for {
		if len(remainder) < length || remainder[:length] != str2 {
			break
		}
		remainder = remainder[length:]
	}
	return remainder
}

```
> 执行用时 :0 ms, 在所有 Go 提交中击败了100.00%
> 内存消耗 :2.3 MB, 在所有 Go 提交中击败了100.00%